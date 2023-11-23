class HashTable:
    def __init__(self,size=10):
        self.size = size
        self.keys = [None] * self.size
        self.values = [None] * self.size

    def __str__(self):
        s = ""
        for k in self:
            if k == None:
                t = "{0:5s}|".format("")
            else:
                t = "{0:-5d}|".format(k)
            s = s + t
        return s

    def __iter__(self):
        for i in range(self.size):
            yield self.keys[i]

    def find_slot(self, key):
        i = self.hash_function(key)
        start = i
        while self.keys[i] is not None and self.keys[i] != key:
            i = (i + 1) % self.size
            if i == start: return 'FULL'
        return i

    def hash_function(self,key):
        return key % self.size

    def set(self, key, value=None):
        i = self.find_slot(key)
        if i == 'FULL':  # H의 용량을 키움
            # self.size += 1
            return None
        # key 값이 이미 있으면 value 수정
        if self.keys[i] is not None:
            self.values[i] = value
        else:
            # key 값이 없다면 key와 value 추가
            self.keys[i] = key
            self.values[i] = value
        return key

    def search(self,key):
        i = self.find_slot(key)
        if self.keys[i] == 'FULL': return None
        if self.keys[i] is not None and self.keys[i] == key:
            return key
        else: return None

    def __getitem__(self, key):
        return self.search(key)
    def __setitem__(self, key, value):
        self.set(key, value)
