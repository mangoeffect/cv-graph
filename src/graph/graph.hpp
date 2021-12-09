/**
 * @file graph.hpp
 * @author mango (2321544362@qq.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef CV_GRAPH_GRAPH_HPP_
#define CV_GRAPH_GRAPH_HPP_

#include "node/node_base.hpp"

namespace cv
{
    class Graph
    {
    private:
        /*data*/
        std::vector<std::vector<char>> fusion_buffers_;                         ///< 融合节点内存
        int tile_rows_;                                                         ///< 平铺处理块行宽度
        int tile_cols_;                                                         ///< 平铺处理块列宽度
        std::vector<cv::Rect> update_rois_;                                     ///< 每次节点update处理roi块集合，由平铺处理划分所得
        std::vector<std::shared_ptr<NodeAbstract>> nodes_;                      ///< 处理流图节点集合
        int num_threads_{4};                                                    ///< 处理线程数
        int max_memory_footprint_;                                              ///< 计算本次处理流程所需最低内存占用 

        bool HaveValidNode();
    public:
        /*member functions*/
        int PushNode(const std::shared_ptr<NodeAbstract>& node);


        void Clear();

        /**
         * @brief 
         * 
         * @param in_mats 
         * @param out_mats 
         * @return int 
         */
        int Run(const std::vector<cv::Mat>& in_mats,  
                const std::vector<cv::Mat>& out_mats);
    }
}//namespace cv

#endif //CV_GRAPH_GRAPH_HPP_
