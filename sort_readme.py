#!/usr/bin/python3

def run():
    file_path = 'README.md'

    keys = [-2,-1]
    lines = {}

    with open(file_path, 'r') as file:
        lines[-2] = file.readline()
        lines[-1] = file.readline()
        for line in file:
            key = int(line.split('|')[1].strip())
            keys.append(key)
            lines[key] = line

    keys.sort()

    with open(file_path, 'w') as file:
        for k in keys:
            file.write(lines[k])

if __name__ == '__main__':
    run()
