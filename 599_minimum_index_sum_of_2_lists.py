import sys 

class Solution(object):
    def findRestaurant(self, list1, list2):
        """
        :type list1: List[str]
        :type list2: List[str]
        :rtype: List[str]
        """
        fav_restaurant_dict1 = {}
        idx = 0
        for restaurant in list1:
            fav_restaurant_dict1[restaurant] = idx
            idx += 1
        fav_restaurant_intersect = []
        min_idx = sys.maxint
        idx = 0
        for restaurant in list2:
            if restaurant in fav_restaurant_dict1:
                idx_sum = idx + fav_restaurant_dict1[restaurant]
                if idx_sum < min_idx:
                    min_idx = idx_sum
                    fav_restaurant_intersect = [restaurant]
                elif idx_sum == min_idx:
                    fav_restaurant_intersect.append(restaurant)
            idx += 1
        return fav_restaurant_intersect

sol = Solution()
list1 = ["Shogun", "Tapioca Express", "Burger King", "KFC"]
list2 = ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
print sol.findRestaurant(list1, list2)
list1 = ["Shogun", "KFC", "Burger King", "Tapioca Express"]
list2 = ["Burger King", "KFC", "Shogun"]
print sol.findRestaurant(list1, list2)

