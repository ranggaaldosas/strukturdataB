 #include<bits/stdc++.h>
using namespace std;

class Graph { // inisialisasi class Graph untuk membuat graf
    private:
        int v;
        string nama[100];
        vector<vector<int>> adj;
        vector<int> dfsResult;
        vector<int> dijkstraRes;
        int dfsWeight; // inisialisasi variabel dfsWeight

    public:
        Graph(int v) { // inisialisasi constructor
            this->v = v;
            vector<int> l (v+1, -1);
            adj.assign(v+1, l);
            dfsResult.assign(v+1, 0);
            vector<int> vec (v+1, 0);
        }

        void addName(int i, string nama){ // inisialisasi method addName untuk menambahkan nama pada setiap node
			this->nama[i]=nama;
			vector<int>arr;
			arr.push_back(i);
			sort(arr.begin(), arr.end());
		}

        void addEdge(int u, int v, int w){ // inisialisasi addEdge untuk menambahkan edge pada graf
            adj[u][v] = w;
        }

        void showMatrix(){ // inisialisasi method showMatrix untuk menampilkan matriks
            cout << "Adjacency Matrix" << endl;
            for (int i = 1; i <= v; i++)
            {
                for ( int j = 1; j <= v; j++)
                {
                    if(adj[i][j] == -1)cout << ".  ";
                    else if (adj[i][j] < 10) cout << adj[i][j] << "  ";
                    else cout << adj[i][j] << " ";
                    
                }
                cout << endl;
            }
            cout << endl;
        }
        
        void BFS(int start, int end){ // inisialisasi method BFS untuk menampilkan jalur terpendek dengan BFS
            cout << endl;
            cout << "BFS" << endl;
            vector<int> visit (v+1, 0);
            vector<int> dist (v+1, INT_MAX);
            vector<int> domain (v+1, 0);
            queue<int> q;

            dist[start] = 0;
            q.push(start);
            visit[start] = true;

            while (!q.empty()) // perulangan untuk mengecek queue kosong/tidak
            {
                int curr = q.front();
                for (int it = 1; it <= v; it++)
                {
                        if(adj[curr][it] != -1 && adj[curr][it] + dist[curr] < dist[it]){
                            dist[it] = adj[curr][it] + dist[curr];
                            domain[it] = curr;
                            q.push(it);
                        }
                }
                q.pop(); // menghapus elemen pertama dari queue
            }
            vector<int> result;
            int i = end;
            while(true){ // perulangan untuk mengecek apakah sudah sampai pada node awal
                result.push_back(i); // menambahkan node ke vector result
                if(i == start) break;
                i = domain[i];
            }

            for (int i = result.size()-1; i >= 0; i--) // perulangan untuk menampilkan jalur terpendek
            {
                cout << "V" <<  result[i] << "-" << nama[result[i]] << ", ";
            }
            
            cout << endl << "Weight = " << dist[end] << endl;
            
        }
        
        void DFS(int start, int end){ // inisialisasi method DFS untuk menampilkan jalur terpendek dengan DFS
            cout << endl;
            cout << "DFS"<< endl;
            dfsWeight = INT_MAX;
            vector<int> path;
            vector<bool> visited (v+1, false);
            solveDFS(start, end, path, visited, 0 ); // memanggil method solveDFS untuk menyelesaikan DFS
            
            for (int i = 0; i < dfsResult.size(); i++) // perulangan untuk menampilkan jalur terpendek
            {
                cout <<"V" << dfsResult[i] << "-" << nama[dfsResult[i]] << ", ";
            }

            cout << endl << "Weight = " << dfsWeight << endl;
        }

        // fungsi untuk menyelesaikan DFS
        void solveDFS(int start, int end, vector<int> path, vector<bool> visited, int currWeight){ 
            if(start == end) { // perulangan untuk mengecek apakah sudah sampai pada node akhir
                path.push_back(end); // menambahkan node ke vector path
                if(currWeight < dfsWeight ) {
                    dfsWeight = currWeight;
                    dfsResult = path;
                }
            }
            visited[start] = true; // mengubah nilai visited menjadi true
            path.push_back(start); // menambahkan node ke vector path
            bool flag = false; // inisialisasi variabel flag
            for ( int it = 1; it <= v; it++) // perulangan untuk mengecek node yang belum dikunjungi
            {
                if(!visited[it] && adj[start][it] != -1){
                    int wtemp = currWeight;
                    wtemp += adj[start][it];
                    flag = true;
                    solveDFS(it, end, path, visited, wtemp);
                }
            }
        }

        int minDist(vector<int> dist, vector<bool> vis){ // inisialisasi method minDist untuk mengecek node dengan jarak terpendek
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

        void dijkstra(int start, int end){ // inisialisasi method dijkstra untuk menampilkan jalur terpendek dengan Dijkstra
            cout << endl << "Dijkstra" << endl;
            vector<int> dist (v+1, INT_MAX);
            vector<bool> vis (v+1, false);
            vector<int> res (v+1, 0);
            dist[start] = 0;
            for (int itv = 1; itv <= v ; itv++) // perulangan untuk mengecek node yang belum dikunjungi
            {
                int min = minDist(dist, vis);
                if (min == -1 ) break;
                vis[min] = true;
                for(int it = 1; it <= v; it++){
                    if (
                        adj[min][it] != -1 &&
                        !vis[it] && 
                        dist[min] + adj[min][it] < dist[it]
                    )
                    {
                        dist[it] = dist[min] + adj[min][it] ; 
                        res[it] = min;
                    }
                }
            }
            int i = res[end];
            vector<int> r;
            r.push_back(end); // menambahkan node ke vector r
            while (true) // perulangan untuk mengecek apakah sudah sampai pada node awal
            {
                r.push_back(i);
                if(i == start) break;
                i = res[i];
            }
            reverse(r.begin(), r.end()); // membalikkan isi vector r
            for (int i = 0; i <  r.size(); i++) // perulangan untuk menampilkan jalur terpendek
            {
                cout << "V" <<  r[i] << "-" << nama[r[i]] << ", ";
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

	// graph.addEdge(0, 1, 3);   // 1 - 2
    // graph.addEdge(0, 2, 2);   // 1 - 3
    // graph.addEdge(1, 3, 2);   // 2 - 4
    // graph.addEdge(1, 5, 6);   // 2 - 6
    // graph.addEdge(3, 4, 4);   // 4 - 5
    // graph.addEdge(4, 7, 1);   // 5 - 8
    // graph.addEdge(3, 8, 7);   // 4 - 9
    // graph.addEdge(8, 9, 7);   // 9 - 10
    // graph.addEdge(9, 10, 2);  // 10 - 11
    // graph.addEdge(10, 11, 1); // 11 - 12
    // graph.addEdge(11, 16, 3); // 12 - 17
    // graph.addEdge(5, 6, 4);   // 6 - 7
    // graph.addEdge(6, 7, 2);   // 7 - 8
    // graph.addEdge(2, 7, 6);   // 3 - 8
    // graph.addEdge(7, 12, 3);  // 8 - 13
    // graph.addEdge(12, 13, 3); // 13 - 14
    // graph.addEdge(12, 14, 4); // 13 - 15
    // graph.addEdge(14, 15, 4); // 15 - 16
    // graph.addEdge(14, 18, 6); // 15 - 19
    // graph.addEdge(18, 17, 2); // 19 - 18
    // graph.addEdge(18, 19, 6); // 19 - 20
  
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
    graph.showMatrix();

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