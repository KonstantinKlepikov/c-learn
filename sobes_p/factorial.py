def inhouse_factorial(x: int) -> int:
    """Напишите, пожалуйста рекурсивное
    вычисление факториала, работающего для всех int
    """
    if x < 0:
        raise ValueError
    elif x == 0 or x == 1:
        return 1
    else:
        return x * inhouse_factorial(x - 1)


if __name__ == '__main__':

    import math

    check = 0
    result = 0
    for i in range(0, 10):
        check += math.factorial(i)
        result += inhouse_factorial(i)

    assert result == check
    print(result)

    try:
        inhouse_factorial(-1)
    except ValueError:
        print('Nonpositive int!')
