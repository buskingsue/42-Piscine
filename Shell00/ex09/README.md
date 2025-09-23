# ft_magic

#### Understanding the writing of the file:
```
41 string 42  42 file
└┬┘└─┬──┘ └┬┘ └──┬───┘
 │   │     │     └─── Text to be displayed when the criteria are found.
 │   │     └───────── The text to be searched is 42.
 │   └─────────────── Search for a string type correspondence.
 └─────────────────── The search begins from byte 42. 
```
It is 41 because the index starts at 0. the 42º is 41. 


To test the Magic File it needs to compiled using the `File` command.
```bash
file -C -m ft_magic
```
After compiled, a .mgc file is generated. To list the files and show the defined correspondence in ft_magic use this command.
```bash
file -m ft_magic.mgc *
```
아래는 네가 올려준 내용을 초등학생도 알기 쉽게 한국어로 풀어 쓴 거야. 핵심은 "magic 파일 한 줄"이 무엇을 의미하는지랑, 그 파일을 컴파일하고 테스트하는 방법이야.

문장(원문)
41 string 42  42 file

이걸 한 글자씩 쉽게 설명하면 이렇게 읽어야 해.

- 41  
  - 이 숫자는 파일 안에서 몇 번째 바이트(칸)에서 찾기를 시작할지 알려줘.  
  - 사람은 1부터 세지만 컴퓨터는 0부터 세기 때문에, "42번째 바이트"를 가리키려면 여기엔 41을 적어야 해. (즉 42번째 = 인덱스 41)

- string  
  - 찾을 값의 종류를 말해. 여기선 "문자열" 즉 글자(텍스트) 형태로 찾겠다는 뜻이야.

- 42  
  - 실제로 파일에서 찾을 텍스트(문자열)이야. 즉 바이트 41(=42번째)에서 "42"라는 글자가 있는지 보는 거야.

- 42 file  
  - 찾았을 때 화면에 보여줄 문구(설명)이야. 조건이 맞으면 file 프로그램이 그 파일에 대해 "42 file"이라고 출력해 줄 거야.

요약(한 줄)
- "파일의 42번째 바이트(인덱스 41)에 '42'라는 문자열이 있으면, 그 파일을 검사할 때 '42 file'이라고 보여줘" 라고 적어놓은 규칙이야.

실제로 시험해 보는 방법 (순서대로)
1) 먼저 ft_magic 라는 텍스트 파일(매직 규칙을 적은 파일)을 만든다. (내용에 위 한 줄이 들어 있어야 해.)

2) 그 파일을 컴파일해서 바이너리 매직 파일(.mgc)을 만든다:
```bash
file -C -m ft_magic
```
- 이 명령을 실행하면 ft_magic.mgc 라는 파일이 생겨.

3) 만든 .mgc 파일로 검사해 본다:
```bash
file -m ft_magic.mgc *
```
- 현재 폴더(*)에 있는 모든 파일을 ft_magic.mgc 규칙으로 검사해서 결과를 보여줘.
- 또는 특정 파일 하나만 검사하려면:
```bash
file -m ft_magic.mgc 어떤파일
```

결과 예시
- 어떤파일의 42번째 바이트(인덱스 41)에 "42"가 있으면, file 명령이 그 파일에 대해:
  42 file
  라고 출력해 줄 거야.

알아두면 좋은 점(간단히)
- offset(여기서는 41)은 0부터 센다는 것 기억하기! (사람식 42번째 = 0부터 센 컴퓨터식 41)
- string은 글자 그대로 찾는 거야. 숫자형으로 해석하는 게 아니고 텍스트 "42"를 찾는 거야.
- 매직 파일에는 string 외에도 byte, short, long 같은 다른 타입 규칙들도 쓸 수 있어.

필요하면 예시 파일을 만들어서 실제로 보여줄게. 어떻게 해보고 싶어? (단계별로 같이 실행해 줄게.)
