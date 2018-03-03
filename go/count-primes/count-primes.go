package count_primes

/*
Description:

Count the number of prime numbers less than a non-negative number, n.
*/

// 最直观判断质数的方法：判断能不能被 2 ~ 根号n 整除

// 此题用  埃拉托斯特尼筛法  更好
// https://zh.wikipedia.org/wiki/%E5%9F%83%E6%8B%89%E6%89%98%E6%96%AF%E7%89%B9%E5%B0%BC%E7%AD%9B%E6%B3%95

func countPrimes(n int) int {
	if n <= 2 {
		return 0
	}

	composite := make([]bool, n)
	num := n / 2

	for i := 3; i*i < n; i += 2 {
		if composite[i] {
			continue
		}

		for j := i * i; j < n; j += 2 * i {
			if !composite[j] {
				num--
				composite[j] = true
			}
		}
	}

	return num
}
