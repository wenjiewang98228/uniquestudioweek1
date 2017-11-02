package hello;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Random;

public class BFS {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int value;
		double num = Math.random();
		if(num<0.5) {
			value = 0;
		}else {
			value = 1;
		}
		
		LinkedList<Character> list_s = new LinkedList<Character>();
		list_s.add('w');
		list_s.add('r');
		LinkedList<Character> list_w = new LinkedList<Character>();
		list_w.add('s');
		list_w.add('i');
		list_w.add('x');
		LinkedList<Character> list_r = new LinkedList<Character>();
		list_r.add('s');
		list_r.add('v');
		LinkedList<Character> list_x = new LinkedList<Character>();
		list_x.add('w');
		list_x.add('i');
		list_x.add('u');
		list_x.add('y');
		LinkedList<Character> list_v = new LinkedList<Character>();
		list_v.add('r');
		LinkedList<Character> list_i = new LinkedList<Character>();
		list_i.add('u');
		list_i.add('x');
		list_i.add('w');
		LinkedList<Character> list_u = new LinkedList<Character>();
		list_u.add('i');
		list_u.add('x');
		list_u.add('y');
		LinkedList<Character> list_y = new LinkedList<Character>();
		list_y.add('u');
		list_y.add('x');
		
		HashMap<Character,LinkedList<Character>> map = new HashMap<Character,LinkedList<Character>>();
		HashMap<Character,Integer> direction = new HashMap<Character,Integer>();		
		
		map.put('s', list_s);
		map.put('w', list_w);
		map.put('r', list_r);
		map.put('x', list_x);
		map.put('v', list_v);
		map.put('i', list_i);
		map.put('u', list_u);
		map.put('y', list_y);
		
		char start = 's';
		
		Queue<Character> q = new LinkedList();
		
		
		q.add(start);
		direction.put(start, 0);
		
		int i=0;
		while(!q.isEmpty()) {
			char top = q.poll();
			
			i++;
			System.out.println("第"+i+"个元素"+top+"到起点s的距离是:"+direction.get(top));
			
			int d = direction.get(top)+1;
			for(Character c : map.get(top)) {
				if(!direction.containsKey(c)) {
					direction.put(c, d);
					q.add(c);
				}
			}
			
		}
		}
}