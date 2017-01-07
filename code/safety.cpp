#include <iostream>
#include <cassert>

const long long mod = 1e9 + 7ll;
const long long coef = 1e6 + 3ll;
const long long inv = 486802543ll;

const int N = 300010;
const int Z = 26;

long long pw_coef[ N ], pw_inv[ N ];

class Hash {
public:
    int len;
    long long value;
    Hash( int _len, long long _val ) : len( _len ), value( _val ) {}
    Hash( void ) {}
};

inline Hash operator + ( Hash H1, Hash H2 ) {
    return Hash( H1.len + H2.len, ( H1.value + pw_coef[ H1.len ] * H2.value ) % mod );
}
inline bool operator == ( Hash H1, Hash H2 ) {
    return H1.len == H2.len and H1.value == H2.value;
}

class SegTree {
public:
    int l, r;
    int idx, shift;
    Hash hash[ Z ];

    SegTree *left, *right;
    SegTree( int _l, int _r ) :
        l( _l ), r( _r ),
        idx( -1 ), shift( 0 ),
        left( nullptr ), right( nullptr )
        {}
};

Hash getHash( int l, int r, int shift );

SegTree* initTree( int a, int b );
void fix( SegTree* );
void propagate( SegTree* );
void update( SegTree*, int l, int r, int k );
void shift( SegTree*, int l, int r, int sh );
void display( SegTree* );

Hash query( SegTree*, int, int );

SegTree *head = nullptr;

long long hashOriginal[ Z ][ N ];
std::string original;

int main( void ) {
    freopen("../test.in","r",stdin);
    freopen("../test.out","w",stdout);
    std::cin.sync_with_stdio( false );
    std::cin.tie( 0 );

    pw_coef[ 0 ] = pw_inv[ 0 ] = 1ll;
    for ( int i = 1 ; i < N ; ++i ) {
        pw_coef[ i ] = ( coef * pw_coef[ i-1 ] ) % mod;
        pw_inv[ i ] = ( inv * pw_inv[ i-1 ] ) % mod;
    }

    // read input
    std::cin >> original;

    // hash original
    for ( int i = 0 ; i < Z ; ++i ) {
        long long ccoef = 1ll;
        for ( int j = 0 ; j < original.length() ; ++j ) {
            hashOriginal[ i ][ j ] = ( ( original[j] - 'a' + i ) % Z ) * pw_coef[ j ];
            if ( j > 0 ) {
                hashOriginal[ i ][ j ] = ( hashOriginal[ i ][ j ] + hashOriginal[ i ][ j-1 ] ) % mod;
            }
        }
    }

    // init tree
    head = initTree( 0, original.size()-1 );
    update( head, 0, original.size()-1, 0 );

    int q;
    std::cin >> q;

    // process queries
    auto res = original;
    while ( q-- ) {
        int type;
        std::cin >> type;
        if ( type == 1 ) {
            // check
            int i, j, k;
            std::cin >> i >> j >> k;

            --i, --j, --k;
            const int len = j - i + 1;

            // std::cout << " input " << i << " " << j << " " << k << std::endl;
            // std::cout << k << " " << k + len - 1 << std::endl;
            // std::cout << " query " << ( query( head, k, k + len - 1 ).value ) << std::endl;
            // std::cout << i << " " << j << std::endl;
            // std::cout << " getHash " << getHash( i, j, 0 ).value << std::endl;
            // std::cout << ( query( head, k, k + len - 1 ) == query( head, i, j ) ? 'Y' : 'N' ) << "\n";
            bool err = false;
            for ( int x = 0 ; x < len ; ++x ) {
                if ( res[ k + x] != res[ i + x ] ) {
                    err = true;
                    break;
                }
            }
            std::cout << ( not err ? 'Y' : 'N' ) << "\n";
        } else if ( type == 2 ) {
            // replace command
            int i, j, k;
            std::cin >> i >> j >> k;
            --i, --j, --k;
            // update( head, i, j, k );
            for ( int x = i ; x <= j ; ++x ) {
                res[ x ] = original[ k + x-i ];
            }
        } else if ( type == 3 ) {
            // shift
            int i, j;
            std::cin >> i >> j;
            --i, --j;
            shift( head, i, j, 1 );
            for ( int x = i ; x <= j ; ++x ) {
                res[ x ] = ( res[ x ] - 'a' + 1 ) % Z + 'a';
            }
        }

        // display( head );
    }

    return 0;
}

void display( SegTree *node ) {
    if ( node == nullptr ) return;
    if ( node->left != nullptr ) propagate( node );
    else std::cout << (char) (node->hash[ node->shift ].value + 'a');
    // else std::cout << node->idx << " ";
    display( node->left );
    display( node->right );
}

SegTree* initTree( int a, int b ) {
    SegTree *node = new SegTree( a, b );
    if ( a < b ) {
        int mid = ( a + b ) / 2;
        node->left = initTree( a, mid );
        node->right = initTree( mid + 1, b );
    }
    return node;
}

void fix( SegTree *node ) {
    for ( int i = 0 ; i < Z ; ++i ) {
        node->hash[ i ] = node->left->hash[ i ] + node->right->hash[ i ];
    }
}

void propagate( SegTree *node ) {
    if ( node->idx != -1 ) {
        update( node->left, node->left->l, node->left->r, node->idx );
        const int sz = node->left->r - node->left->l + 1;
        update( node->right, node->right->l, node->right->r, node->idx + sz );
        node->idx = -1;
    }

    if ( node->shift ) {
        shift( node->left, node->l, node->r, node->shift );
        shift( node->right, node->l, node->r, node->shift );
        node->shift = 0;
    }

    fix ( node );
}

void update( SegTree *node, int l, int r, int k ) {
    if ( r < node->l or node->r < l ) return;
    // std::cout << " update " << node->l << " " << node->r << " " << l << " " << r << " " << k << std::endl;
    if ( l <= node->l and node->r <= r ) {
        const int sz = node->r - node->l + 1;
        for ( int i = 0 ; i < Z ; ++i ) {
            node->hash[ i ] = getHash( k, k + sz - 1, i );
        }
        node->idx = k;
        node->shift = 0;
        return;
    }

    propagate( node );

    const int mid = ( node->l + node->r ) / 2;
    if ( mid < l ) {
        update( node->right, l, r, k );
    } else if ( r <= mid ) {
        update( node->left, l, r, k );
    } else {
        update( node->left, l, mid, k );
        update( node->right, mid + 1, r, k + mid - l + 1 );
    }
    fix( node );
}

void shift( SegTree *node, int l, int r, int sh ) {
    if ( r < node->l or node->r < l ) return;
    if ( l <= node->l and node->r <= r ) {
        node->shift = ( node->shift + sh ) % Z;
        return;
    }

    propagate( node );

    shift( node->left, l, r, sh );
    shift( node->right, l, r, sh );
    fix( node );
}

Hash query( SegTree *node, int l, int r ) {
    if ( r < node->l or node->r < l ) return Hash( 0, 0 );
    if ( l <= node->l and node->r <= r ) {
        return node->hash[ node->shift ];
    }
    propagate( node );
    return query( node->left, l, r ) + query( node->right, l, r );
}

Hash getHash( int i, int j, int shift ) {
    assert ( j < original.size() );
    shift %= Z;
    long long ans = hashOriginal[ shift ][ j ];
    if ( i > 0 ) ans -= hashOriginal[ shift ][ i-1 ];
    ans = ( ans % mod * pw_inv[ i ] ) % mod;
    ans = ( ans + mod ) % mod;

    // long long check = 0ll;
    // for ( int k = i ; k <= j ; ++k ) {
    //     int val = ( original[ k ] - 'a' + shift ) % Z;
    //     check = ( check + pw_coef[ k-i ] * val ) % mod;
    // }
    // assert( check == ans );
    // std::cout << " getHash " << i << " " << j << " " << shift << " : " << ans << std::endl;
    return Hash( j-i+1, ans );
}
