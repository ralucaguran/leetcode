import string
import itertools


class Codec:
    
    ALNUM_COMBI = itertools.combinations(string.digits + string.ascii_letters, 6)
    long_2_short_urls = {}
    short_2_long_urls = {}

    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.
        
        :type longUrl: str
        :rtype: str
        """
        short_url = ''.join(next(Codec.ALNUM_COMBI))
        Codec.long_2_short_urls[longUrl] = short_url
        Codec.short_2_long_urls[short_url] = longUrl
        return short_url

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.
        
        :type shortUrl: str
        :rtype: str
        """
        return Codec.short_2_long_urls[shortUrl]
        

# Your Codec object will be instantiated and called as such:
codec = Codec()
url = 'https://leetcode.com/problems/design-tinyurl'
assert codec.decode(codec.encode(url)) == url

