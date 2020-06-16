//lower_bound
int start = 0, end = n-1, idx = -1;
while (start <= end)
{
    int mid = start + (end - start)/2;
    if (nums[mid] < target)
        start = mid+1;
    else
        end = mid-1;
    if(nums[mid] < target && nums[idx] != target)
        idx = mid;
    if(nums[mid] == target)
        idx = mid;
}
return idx;

//upper_bound = lower_bound(target+1)-1
int start = 0, end = n-1, idx = -1;
while (start <= end)
{
    int mid = start + (end - start)/2;
    if (nums[mid] <= target)
        start = mid+1;
    else
        end = mid-1;
    if(nums[mid] > target)
        idx = mid;
}
return idx;
