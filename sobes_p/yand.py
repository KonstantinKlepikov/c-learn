def num_of_forms(n: int) -> int:
    """
    Для заданного числа N найти количество способов его записи
    в виде суммы положительных чисел (само число N также считать
    одной из форм записей такой суммы, т.е. N = N).
    """

    def func(p: int) -> list[int]:
        m = 0
        for i in range(len(p)-1):
            if p[i] < p[m]:
                m = i
        p[m] += 1
        p[-1] -= 1
        return p[0:m+1]+[1 for _ in range(sum(p[m+1:]))]

    c = 0
    p = [1 for _ in range(n)]
    while p:
        print(p)
        c += 1
        if len(p) == 1: break
        p = func(p)

    return c

def max_nod(d: list[int]) -> int:
    """Найти наибольший общий делитель всех чисел в заданном диапазоне [L, R].
    """
    for i in range(1, max(d)+1):
        if (not d[0] % i) & (not d[1] % i):
            r = i
    return r



if __name__ == '__main__':

    n = num_of_forms(5)
    print(n)

    print(max_nod([12, 38]))