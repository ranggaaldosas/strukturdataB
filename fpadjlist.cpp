#include<bits/stdc++.h>
using namespace std;

class Graph { // definisi kelas Graph
    private:
        int v;
        string nama[100];
        vector<list<int>> adj;
        map<pair<int,int>, int> weight; // map untuk menyimpan bobot
        vector<int> dfsResult;
        int dfsWeight; // variabel untuk menyimpan bobot dari dfs
        vector<int> dijkstraRes; // variabel untuk menyimpan hasil dari dijkstra
    public:
        Graph(int v) { // konstruktor
            this->v = v;
            list<int> l;
            adj.assign(v+1, l); // inisialisasi adj dengan list kosong
            dfsResult.assign(v+1, 0); // inisialisasi dfsResult dengan 0, v+1 untuk menghindari index out of bound
            vector<int> vec (v+1, 0); // inisialisasi vector vec dengan 0, v+1 untuk menghindari index out of bound
        }
        void addName(int i, string nama){ // fungsi untuk menambahkan nama pada vertex
			this->nama[i]=nama;  // menyimpan nama pada vertex ke-i
			vector<int>arr; // inisialisasi vector arr
			arr.push_back(i); // memasukkan vertex ke-i ke dalam vector arr
			sort(arr.begin(), arr.end()); // mengurutkan vector arr
		}
        void addEdge(int u, int v, int w){ // fungsi untuk menambahkan edge
            adj[u].push_back(v); // menambahkan edge dari u ke v
            weight.insert({make_pair(u,v), w}); // menyimpan bobot dari edge u ke v
        }
		void showList(){ // fungsi untuk menunjukan adj list
			cout << "Adjacency List" <<endl;
            list<int>::iterator it; // inisialisasi iterator
            for(int i=1; i < v; i++){ // melakukan iterasi untuk setiap vertex
                cout << "V"<< i <<"-" << nama[i] ;
                for(it=adj[i].begin(); it != adj[i].end(); ++it){
                    cout << " -> V" << *it << "-" << nama[*it] <<"[" <<  weight[make_pair(i, *it)] << "]";
                }                                                                 
                cout << endl;
        	}
        	cout << endl;        	
		}
        void BFS(int start, int end){ // fungsi untuk menunjukan BFS
            cout << endl;
            cout << "BFS" << endl;
            vector<int> visit (v+1, 0); // inisialisasi vector visit dengan 0, v+1 untuk menghindari index out of bound
            vector<int> dist (v+1, INT_MAX); // inisialisasi vector dist dengan INT_MAX, v+1 untuk menghindari index out of bound
            vector<int> domain (v+1, 0); // inisialisasi vector domain dengan 0, v+1 untuk menghindari index out of bound
            queue<int> q; 

            dist[start] = 0; // inisialisasi dist dari start dengan 0
            q.push(start); // memasukkan start ke dalam queue
            visit[start] = true;

            while (!q.empty()) { // melakukan iterasi selama queue tidak kosong
                int curr = q.front();
                list<int>::iterator it;
                for (it = adj[curr].begin(); it != adj[curr].end(); it++){ // melakukan iterasi untuk setiap vertex yang terhubung dengan vertex curr agar bisa diakses
                    if(weight[make_pair(curr, *it)] + dist[curr] < dist[*it]){ 
                        dist[*it] = weight[make_pair(curr, *it)] + dist[curr];
                        domain[*it] = curr;
                        q.push(*it);
                    } // nyari vertex terdekat dari qfront, if untuk menentukan weight dari vertex yang terkecil dari tiap vertex terus dipush
                } // jika weight dari edge curr ke vertex yang terhubung + dist dari curr < dist dari vertex yang terhubung maka dist dari vertex yang terhubung diupdate
                q.pop(); // menghapus vertex yang sudah diakses
            }
           
            vector<int> result;
            int i = end;
            while(true){ // melakukan iterasi untuk mencari path dari start ke end
                result.push_back(i);
                if(i == start) break;
                i = domain[i];
            }
            for (int i = result.size()-1; i >= 0; i--){ // menampilkan path dari start ke end
                cout << "V" <<  result[i] << "-" << nama[result[i]] << ", ";
            }
            cout << endl << "Weight = " << dist[end] << endl; // print weight dari start ke end
        }
        
        // fungsi DFS untuk mencari path dari start ke end
        void DFS(int start, int end){ 
            cout << endl;
            cout << "DFS" << endl;
            dfsWeight = INT_MAX;
            vector<int> path;
            vector<bool> visited(v+1, false);
            solveDFS(start, end, path, visited, 0 ); // memanggil fungsi solveDFS
            
            for (int i = 0; i < dfsResult.size(); i++){ // perulangan untuk menampilkan path dari start ke end
                cout <<"V" << dfsResult[i] << "-" << nama[dfsResult[i]] << ", ";
            }
            cout << endl << "Weight = " << dfsWeight << endl;
        }
        void solveDFS(int start, int end, vector<int> path, vector<bool> visited, int currWeight){
            // pengkondisian untuk menentukan apakah vertex yang diakses adalah vertex yang dicari
            if(start == end) {
                path.push_back(end);
                if(currWeight < dfsWeight ) {
                    dfsWeight = currWeight;
                    dfsResult = path;
                }
            }   
            visited[start] = true;
            path.push_back(start); // memasukkan vertex yang sudah diakses ke dalam path
            list<int>::iterator it;
            // melakukan iterasi untuk setiap vertex yang terhubung dengan vertex start agar bisa diakses            
            for ( it = adj[start].begin(); it != adj[start].end(); it++){
                if(!visited[*it]){
                    int wtemp = currWeight;
                    wtemp += weight[make_pair(start, *it)];
                    solveDFS(*it, end, path, visited, wtemp);
                }
            }
        }
        // fungsi untuk menentukan vertex terdekat dari vertex yang diakses
        int minDist(vector<int> dist, vector<bool> vis){
            int min = INT_MAX;
            int min_index = INT_MAX;
            int flag = 0;
            for (int i = 1; i <= v; i++) {
                if(!vis[i] && dist[i] < min) {
                    min = dist[i];
                    min_index = i;
                    flag = 1;
                }
            }
                if ( flag == 1 ) 
                    return min_index;
                else 
                    return -1;
        }

        // fungsi Dijkstra untuk mencari path dari start ke end
        void dijkstra(int start, int end){
            cout << endl << "Dijkstra" << endl;
            vector<int> dist (v+1, INT_MAX);
            vector<bool> vis (v+1, false);
            vector<int> res (v+1, 0);

            dist[start] = 0;

            for (int itv = 1; itv <= v ; itv++) // 
            {
                int min = minDist(dist, vis);
                if (min == -1 ) break;
                vis[min] = true;
                list<int>::iterator it;
                // melakukan iterasi untuk setiap vertex yang terhubung dengan vertex min agar bisa diakses
                for(it = adj[min].begin(); it != adj[min].end(); ++it){
                    if (
                        weight[make_pair(min, *it)] &&
                        !vis[*it] && 
                        dist[min] + weight[make_pair(min, *it)]  < dist[*it]
                    )
                    {
                        dist[*it] = dist[min] + weight[make_pair(min, *it)]; 
                        res[*it] = min;
                    }
                }
            }
            int i = res[end];
            vector<int> r;
            r.push_back(end);
            while (true){
                r.push_back(i);
                if(i == start) break;
                i = res[i];
            }
            reverse(r.begin(), r.end()); // membalikkan path dari start ke end
            for (int i = 0; i <  r.size(); i++){ // perulangan untuk menampilkan path dari start ke end
                cout <<"V" <<  r[i] << "-" << nama[r[i]] << ", ";
            }
            cout << endl << "Weight = " << dist[end] << endl;
        }
};

int main(){
    Graph graph(20);
    graph.addName(1, "Home");
    graph.addName(2, "RestoranUrban");
    graph.addName(3, "ComoPark");
    graph.addName(4, "ITCFatmawati");
    graph.addName(5, "BlokMSquare"); 
    graph.addName(6, "LippoMall"); 
    graph.addName(7, "KantorImigrasi"); 
    graph.addName(8, "BitterswtNajla"); 
    graph.addName(9, "MarkasPolisi"); 
    graph.addName(10, "MercureHotel"); 
    graph.addName(11, "MonumenPatung"); 
    graph.addName(12, "TebetPark"); 
    graph.addName(13, "BadanIntelejen"); 
    graph.addName(14, "KalibataCity"); 
    graph.addName(15, "RestuHospital"); 
    graph.addName(16, "UniversitasKristen"); 
    graph.addName(17, "MCDOtista"); 
    graph.addName(18, "HalimAirport"); 
    graph.addName(19, "BalaiPrajurit"); 
    graph.addName(20, "CipinangMall"); 

	graph.addEdge(1, 2, 3);   // 1 - 2
    graph.addEdge(1, 3, 2);   // 1 - 3
    graph.addEdge(2, 4, 2);   // 2 - 4
    graph.addEdge(2, 6, 6);   // 2 - 6
    graph.addEdge(4, 5, 4);   // 4 - 5
    graph.addEdge(5, 8, 1);   // 5 - 8
    graph.addEdge(4, 9, 7);   // 4 - 9
    graph.addEdge(9, 10, 7);   // 9 - 10
    graph.addEdge(10, 11, 2);  // 10 - 11
    graph.addEdge(11, 12, 1); // 11 - 12
    graph.addEdge(12, 17, 3); // 12 - 17
    graph.addEdge(6, 7, 4);   // 6 - 7
    graph.addEdge(7, 8, 2);   // 7 - 8
    graph.addEdge(3, 8, 6);   // 3 - 8
    graph.addEdge(8, 13, 3);  // 8 - 13
    graph.addEdge(13, 14, 3); // 13 - 14
    graph.addEdge(13, 15, 4); // 13 - 15
    graph.addEdge(15, 16, 4); // 15 - 16
    graph.addEdge(15, 19, 6); // 15 - 19
    graph.addEdge(19, 18, 2); // 19 - 18
    graph.addEdge(19, 20, 6); // 19 - 20
  
    graph.showList(); // menampilkan list vertex dan edge

	int start, end;
	cout << "start : ";
	cin >> start;
	cout << "end : ";
	cin >> end;

	graph.BFS(start, end);
    graph.DFS(start, end);
    graph.dijkstra(start, end);

    return 0;
}