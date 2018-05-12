f = [1, 5]
g = [1, 7]
mod = 1000000009

for i in range(2, 1000):
    f.append((g[i-1]+2*g[i-2])%mod)
    g.append((f[i-1]+3*f[i-2])%mod)


print("g4", g[3])
print("f4", f[g[3]-1])

print("g5", g[4])
print("f5", f[g[4]-1])

print("g6", g[5])
print("f6", f[g[5]-1])

print("g6", g[5])
print("f6", f[g[5]-1])