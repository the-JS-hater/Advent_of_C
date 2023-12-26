def read_input(day: int, split=True):
    with open(f'input-{day}.txt') as f:
        input_ = f.read()
        if split:
            return input_.splitlines()
        return input_