/* 
				jQuery 的节点操作
					+ 原生 Js 的节点操作
						创建节点，插入节点，删除节点，替换节点，克隆节点
					+ jQuery的节点操作
						创建节点，插入节点，删除节点，替换节点，克隆节点
				
				1. 创建节点
					+$(html 结构字符串)
					=>选择器
					=> dom 对象
					=> html 字符串
				2. 插入节点
					+ 内部插入
						+ 2.1 append()
							=> 语法： 父元素.append(子元素)
						+ 2.2 appendTo()
							=> 语法： 子元素.append(父元素)
						+ 2.3 prepend()
						+ 2.4 prependTo()
						+ 
					+ 外部插入
						+ 2.5 after()
						+ 2.6 insertAfter()
						+ 2.7 before()
						+ 2.8 insertBefore()
				3. 删除节点
					1. remove() 把自己移除
					2. empty() 把后代节点全部移除
					
				4. 替换节点
					1. replaceWith() 
						老节点.replaceWith(新节点);
					2. replaceAll()
						新节点.replaceAll(老节点)
				5. 克隆节点
					+ clone()
						元素集合.clone
						第一个参数是false,表示是否克隆本身的事件
						第二个参数是默认跟随第一个，表示后代事件是否克隆
						当第一参数是false,第二个参数无意义
					+ c
			*/
