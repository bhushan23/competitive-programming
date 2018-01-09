class Solution {
public:
    
    
    unordered_map<string, string> mapStr;
    string mapString = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        srand(time(NULL));
        string encoded(6,'-');
        
        do {
            for (int i = 0; i < 6; ++i) {
                encoded[i] = mapString[rand() % 62];
            }
        } while(mapStr.find(encoded) != mapStr.end());
        mapStr[encoded] = longUrl;
        return encoded;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mapStr[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
