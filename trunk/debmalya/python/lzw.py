
def compress(uncompressed):
   # """Compress a string to a list of output symbols."""
 
    # Build the dictionary.
    dict_size = 256
    dictionary = {}
    for i in range(dict_size):
        dictionary[chr(i)] = chr(i)
 
    w = ''
    result = []
    for c in uncompressed:
        wc = w + c
        if wc in dictionary:
            w = wc
        else:
            result.append(dictionary[w])
            # Add wc to the dictionary.
            dictionary[wc] = dict_size
            dict_size += 1
 
            w = c
    # Output the code for w.
    if w:
        result += [char for char in w]
    return result;

a = compress('TOBEORNOTTOBEORTOBEORNOT');
print a;

