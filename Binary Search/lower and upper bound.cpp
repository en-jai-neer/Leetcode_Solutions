//lower_bound
int start = 0, end = n-1, idx = -1;
while (start <= end)
{
    int mid = start + (end - start)/2;
    if (nums[mid] < target)
        start = mid+1;
    else
        end = mid-1;
    if(nums[mid] == target)
        idx = mid;
}
return idx;

//upper_bound
int start = 0, end = n-1, idx = -1;
while (start <= end)
{
    int mid = start + (end - start)/2;
    if (nums[mid] <= target)
        start = mid+1;
    else
        end = mid-1;
    if(nums[mid] == target)
        idx = mid;
}
return idx;
