package single_number_ii

// 这种方法可以拓展为 每个元素都出现了k次，只有一个出现了1次，找出它
func singleNumberII(nums []int) int {
	result := 0

	// int 是64位？
	for bit := uint(0); bit < 64; bit++ {
		count := 0 // 保存这个二进制位上的1出现的次数，每个位上都应该是3的倍数，除了要找的那一个
		for i := 0; i < len(nums); i++ {
			if (nums[i]>>bit)&1 > 0 {
				count++
			}
		}
		result |= ((count % 3) << bit)
	}

	return result
}
