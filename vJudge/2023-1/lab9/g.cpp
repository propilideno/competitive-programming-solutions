/* ########################## Template available in: https://propi.dev/cp  ########################## */
//#pragma GCC optimize("-O3","-funroll-all-loops","-ffast-math") //Uncomment for a faster runtime
#include <bits/stdc++.h>
//Debug methods
#define _(x) {cout << #x << " = " << x << endl;} //Print with endl
#define __(x) {cout << #x << " = " << x << " | ";} //Print without endl
#define _vec(x) {cout << #x << " = "; for(int i : x){cout << i << " ";} cout << endl;} //Print entire vector
#define _pair(x) {cout << #x << " = | " << "1st: " << x.first << " | " << "2nd: " << x.second << endl;} //Print pair
#define __time__ { auto duration = chrono::duration<double>( /* Show runtime */ \
std::chrono::high_resolution_clock::now() - beg); cout<<"Time: "<<duration.count()<<endl;}
#define __log__ { std::FILE* file = std::freopen("LOG.txt", "w", stdout); }
//Constants
const auto beg = std::chrono::high_resolution_clock::now(); //Begining of the program
const double PI = acos(-1); //PI
const double E = 1e-8; //Small Number (10^-8)
const int INF_P = 0x3f3f3f3f; //Max positive integer that don't cause overflow when doubled
const int INF_N = 0xcfcfcfcf; //Min negative integer that don't cause underflow when doubled
const int MOD = 1e9+7; //Mod operations (prime number)
//Shortened Methods
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
//Shortened Types
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef std::pair <ll, ll> pll;
typedef std::vector<ll> vll;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef std::vector<std::pair<int, int> > vpii;
typedef std::map<int, int> mii;
typedef std::map<ll, ll> mll;
typedef std::pair<int, int> pii;
typedef std::pair<std::string, int> psi;
//loops
#define f(i,n) for(int i=0;i<n;i++) //From 0 to n-1
#define rf(i,n) for(int i=n-1;i>=0;i--) //From n-1 to 0
#define F(i,a,b) for(int i=a;i<b;i++) // From a to b-1
#define RF(i,a,b) for(int i=a;i>=b;i--) // From a to b-1
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
#define RFOR(it,c) for ( __typeof((c).rbegin()) it=(c).rbegin(); it!=(c).rend(); it++ )
#define REP(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end();)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define sz(x) ((int)(x).size())
#define ms(arr,val) memset(arr,val,sizeof(arr))
//IO Optimization
#define __SpeedUP__ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// Custom Data Structs
struct Graph { // Call like: Graph G(n); G.addEdge(u,v);
    int n; vector<unordered_set<int>> adj; Graph(int size) : n(size) { adj.resize(size); }
    void addEdge(int u, int v) { adj[u].insert(v); }
	void removeEdge(int u, int v) { adj[u].erase(v); }
	void removeNeighbors(int v){ adj[v].clear(); }
};
// HEADERS
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>; //Min Heap
struct Graph; //Graph with adjacency list					 // vector <bool> visited(n,false);
template <template<typename...> class Container, typename T> // DFS: dbfs<stack,int>(G,v,visited)
bool dbfs(Graph& G, int v, int out, vector<bool>& visited);			 // BFS: dbfs<queue,int>(G,v,visited)

/* ################################################################################################## */


int main(){
	//SpeedUP; //Uncomment for a faster runtime
	__log__;
	int t, n; cin >> t;
	f(k,t){
		cout << "Case " << k+1 << ":" << endl;
		cin >> n; Graph G(n);
		f(i,n){ //Construct Graph
			f(j,n){
				int hasEdge; cin >> hasEdge;
				if(hasEdge == 1) G.addEdge(i,j);
			}
		}
		f(i,n){ // Verify Domination for every Edge
			cout << "+" << string(2*n-1, '-') << "+" << endl;
			cout << "|";
			f(j,n){
				Graph A(G);
				vector<bool> visited(n,false); bool dominate;
				if(i == j) dominate = !(dbfs<stack,int>(A,0,j,visited));
				else{
					A.removeNeighbors(i);
					dominate = dbfs<stack,int>(A,0,j,visited);
				}
				cout << (dominate ? "Y|" : "N|");
			} cout << endl;
		}
		cout << "+" << string(2*n-1, '-') << "+" << endl;
	}
	
	__time__
}


/* ################################################################################################## */

template <template<typename...> class Container, typename T>
bool dbfs(Graph& G, int v, int out, vector<bool>& visited) {
    Container<T> arr; arr.push(v); visited[v] = true;

    while (!arr.empty()) {
		if constexpr(is_same<Container<T>, stack<typename Container<T>::value_type>>::value) {
			v = arr.top(); // Use top if using std::stack
		} else { v = arr.front(); } arr.pop(); // front if std::queue

		_(v)

		if(v == out){
			return 0; //Don't dominate, because we reach out
		}

        for (int w : G.adj[v]) {
            if (!visited[w]) {
                arr.push(w); visited[w] = true;
            }
        }
    }
	return 1; // Dominate
}

/* ########################## Template available in: https://propi.dev/cp  ########################## */
