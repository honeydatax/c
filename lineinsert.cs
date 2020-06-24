using System;

namespace logic{
	
	class logics{
		public class lineInsert{
			public string value ="";
			public int x=0;
			public int y=0;
			public int length=0;
			public int max=79;
			int cursor=0;
			
			public lineInsert(){
			}
			public string input(string back){
				ConsoleKeyInfo key=new ConsoleKeyInfo();
				string s="";
				char last=' ';
				char c32=' ';
				char c13='\r';
				int b=32;
				int bb=32;
				bool exits=false;
				int i=0;
				x=Console.CursorLeft;
				y=Console.CursorTop;
				cursor=value.Length;
				cursorinsert();
				while(!exits){
					try{
						key=Console.ReadKey(true);
						b=Convert.ToInt16(key.Key);
					}catch{
						b=0;
					}
					
					if(key.Key==ConsoleKey.UpArrow || key.Key==ConsoleKey.DownArrow || key.Key==ConsoleKey.PageDown || key.Key==ConsoleKey.PageUp){
								value=back;
								length=back.Length;
								cursor=value.Length;
								cursorinsert();
								bb=0;
								b=1;

					}
					//if(key.Key==ConsoleKey.UpArrow || key.Key==ConsoleKey.DownArrow || key.Key==ConsoleKey.Home || key.Key==ConsoleKey.LeftArrow || key.Key==ConsoleKey.RightArrow || key.Key==ConsoleKey.End || key.Key==ConsoleKey.PageDown || key.Key==ConsoleKey.PageUp){
					if(key.Key==ConsoleKey.LeftArrow ){

								value=value.Replace("_","");
								cursor--;
								cursorinsert();
								bb=0;
								b=1;

					}
					if(key.Key==ConsoleKey.RightArrow ){

								value=value.Replace("_","");
								cursor++;
								cursorinsert();
								bb=0;
								b=1;

					}


					if(key.Key==ConsoleKey.End ){

								value=value.Replace("_","");
								cursor=value.Length;
								cursorinsert();
								bb=0;
								b=1;

					}
					if(key.Key==ConsoleKey.Home ){

								value=value.Replace("_","");
								cursor=0;
								cursorinsert();
								bb=0;
								b=1;

					}

					if(key.Key==ConsoleKey.Enter)exits=true;
					if((key.Key==ConsoleKey.Delete || key.Key==ConsoleKey.Backspace) && length>0){
					
								s="";
								
								value.Replace("_","");
								cursor--;
								for(i=0;i<length;i++){
									if(!(i==cursor))s=s+value[i];
								}
								value=s;
								
								cursorinsert();
								bb=0;
								b=1;
								 
					
					}
					
					if(key.KeyChar>=' ' && length<max){
					
						value=value.Replace("_",key.KeyChar.ToString());
						
						cursor++;
						cursorinsert();
					}
					
				
				}
				value=value.Replace("_","");
				cursorinsert();
				value=value.Replace("_","");
				length=value.Length;
				return value;
			}
			
			
			public void cursorinsert(){
				string ss="";
				int ii=0;
				length=value.Length;
				if(cursor>length)cursor=length;
				if(cursor<0)cursor=0;
				
				for(ii=0;ii<value.Length+1;ii++){
					if(cursor==ii)ss=ss+"_";
					if(ii<value.Length)ss=ss+value[ii];
				}
				
				value=ss;
				Console.CursorLeft=x;
				Console.CursorTop=y;
				Console.Write(value+"  ");
				Console.CursorLeft=x+cursor;
				Console.CursorTop=y;
				

				
			}

		}
		
		static void Main(string[] args){
			lineInsert inputs = new lineInsert();
			
			Console.Write("\n!{0}",inputs.input("back line..."));
				

		}

		
	}
}






