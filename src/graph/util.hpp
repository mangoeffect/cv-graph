/**
 * @file util.hpp
 * @author mango (2321544362@qq.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef CV_GRAPH_UTIL_HPP_
#define CV_GRAPH_UTIL_HPP_

namespace cv
{
    template<typename T>
    void CopyToWithZeroBound(const cv::Mat& in, 
                             cv::Mat& out, 
                             const cv::Rect& roi, 
                             const int& rr_ori, 
                             const int& cc_ori);
}//namespace cv

#endif //CV_GRAPH_UTIL_HPP_
