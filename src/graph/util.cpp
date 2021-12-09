/**
 * @file util.cpp
 * @author mango (2321544362@qq.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "util.hpp"

namespace cv
{
    template<typename T>
    void Graphic::CopyToWithZeroBound(const cv::Mat& in, cv::Mat& out, const cv::Rect& roi, const int& rr_ori, const int& cc_ori)
    {
        for(int r=roi.y, rr=rr_ori; r<roi.y + roi.height; r++, rr++)
        {
            T* out_ptr = out.ptr<T>(rr);
            for(int c=roi.x, cc=cc_ori; c<roi.x + roi.width; c++, cc++)
            {
                if(r<0 || r>=in.rows || c<0 || c>=in.cols)
                {
                    out_ptr[cc] = 0;
                    continue;
                }else
                {
                    const T* in_ptr = in.ptr<T>(r);
                    out_ptr[cc] = in_ptr[c];
                }
            }
        }
    }
}//namespace cv
