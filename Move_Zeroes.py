def moveZeroes(self, nums):
         count = 0 # Count of non-zero elements
         n=len(nums)
         for i in range(n):
             if nums[i] != 0:
                 nums[count] = nums[i]
                 count+=1
         while count < n:
             nums[count] = 0
             count += 1
