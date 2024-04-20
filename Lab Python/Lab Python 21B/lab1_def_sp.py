def add_six_base(a, b):
    # Convert two numbers to strings
    a_str = str(a)
    b_str = str(b)
    # Determine the length of the strings
    a_len = len(a_str)
    b_len = len(b_str)
    # Determine the maximum length of strings
    max_len = max(a_len, b_len)
    a_str = a_str.zfill(max_len)
    b_str = b_str.zfill(max_len)
    result = ''
    carry = 0
    for i in range(max_len - 1, -1, -1):
        # Get numbers from strings
        a_digit = int(a_str[i])
        b_digit = int(b_str[i])
        sum_digit = a_digit + b_digit + carry
        # Define the transfer
        if sum_digit >= 6:
            carry = 1
            sum_digit -= 6
        else:
            carry = 0
        result = str(sum_digit) + result
    if carry == 1:
        result = '1' + result
    return result