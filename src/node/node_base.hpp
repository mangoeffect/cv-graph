/**
 * @file node_base.hpp
 * @author mango (2321544362@qq.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef CV_GRAPH_NODE_BASE_HPP_
#define CV_GRAPH_NODE_BASE_HPP_

//cpp standard
#include <string>
#include <vector>
#include <memory>

//opencv
#include "opencv2/opencv.hpp"

namespace cv
{
    /**
     * @brief 节点抽象类
     * 
     */
    class NodeAbstract
    {
    private:
        /*data*/
        std::string name_;                      ///< 节点名称
        int input_data_type_{CV_16U};           ///< 输入图像数据类型
        int input_data_num_{1};                 ///< 输入数据数量
        int output_data_type_{CV_16U};          ///< 输出图像数据类型
        int output_data_num_{1};                ///< 输出数据数量

        int op_row_{3};                         ///< 处理数据行数
        int op_col_{3};                         ///< 处理数据列数
        int padded_row_{0};                     ///< 数据拓宽函数
        int padded_col_{0};                     ///< 数据拓宽列数

        int current_row_{0};                    ///< 当前行数，线性化处理时需要全局索引
        int current_col_{0};                    ///< 当前列数数，线性化处理时需要全局索引

        std::vector<cv::Mat> in_datas_;         ///< 输入数据，为更新节点内存地址
        std::vector<cv::Mat> out_datas_;        ///< 输出数据，为更新节点内存地址
        int index_flag_{0};                     ///< 节点索引标号，0或1,用于判断节点处于奇数还是偶数位置
        bool have_special_datas_{false};        ///< 节点拥有特殊数据头
    public:
        virtual ~NodeAbstract() = default;

        virtual int Run() = 0;

        virtual std::unique_ptr<NodeAbstract> Clone() const = 0;
    }

   /**
    * @brief 原型模式实现clone子类节点
    * 
    * @tparam Derived 
    */
    template <typename Derived>
    class Node : public NodeAbstract 
    {
    public:
        std::unique_ptr<NodeAbstract> Clone() const override 
        {
            return std::make_unique<Derived>(static_cast<Derived const&>(*this));
        }
    protected:
        Node() = default;
        Node(const Node&) = default;
        Node(Node&&) = default;
    };

}//namespace cv

#endif //CV_GRAPH_NODE_BASE_HPP_
