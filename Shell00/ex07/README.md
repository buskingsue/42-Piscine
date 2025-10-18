# Diff

The `patch` command applies changes of files to other files. The ** a ** and ** sw.diff ** files need to be in the same folder.

`a` Original file name.

`sw.diff` file that contains the differences.

`-o` generates an output with the name `b` with the differences between file 'a' and 'sw.siff'.

```bash
patch a sw.diff -o b
```

좋아요 👍
이 내용을 단계별로 쉽게 이해할 수 있도록 해석해드릴게요.

---

## 🧩 명령어 요약

```
patch a sw.diff -o b
```

---

## 🧠 개념 설명

### 1️⃣ `diff` 명령어란?

* `diff`는 두 파일의 **차이점(differences)** 을 비교하는 리눅스 명령어입니다.
* 보통 이렇게 사용합니다:

  ```bash
  diff original.txt new.txt > sw.diff
  ```

  → 두 파일의 차이점을 `sw.diff` 파일로 저장합니다.
  즉, `sw.diff`는 **패치(patch)** 정보가 담긴 파일입니다.

---

### 2️⃣ `patch` 명령어란?

* `patch`는 `diff` 명령으로 만들어진 **차이(diff) 파일(sw.diff)** 을 이용해서
  **원본 파일(a)** 에 변경 사항을 적용하는 명령어입니다.

---

## 🧾 명령어 해석

```
patch a sw.diff -o b
```

| 요소        | 의미                       |
| --------- | ------------------------ |
| `patch`   | 변경 내용을 적용하는 명령어          |
| `a`       | 원본 파일 이름 (original file) |
| `sw.diff` | 변경 사항이 기록된 diff 파일       |
| `-o b`    | 결과를 새로운 파일 `b`로 출력       |

---

## 📚 실행 결과 요약

* 원본 파일: **a**
* 차이 정보: **sw.diff**
* 결과 파일: **b**

즉 👇

> “`a` 파일에 `sw.diff`에 기록된 변경 사항을 적용해서 `b` 파일을 만든다.”

---

## 🔧 예시

```bash
# 1. 원본 파일 생성
echo "Hello World" > a

# 2. 수정본 생성
echo "Hello AI World" > new

# 3. 차이 저장
diff a new > sw.diff

# 4. patch로 변경 적용
patch a sw.diff -o b

# 5. 결과 확인
cat b
```

📄 출력:

```
Hello AI World
```

---

즉,
`diff` → 변경사항 저장
`patch` → 변경사항 적용

이 두 명령어를 함께 쓰면 **파일 버전 관리나 코드 수정 자동화**가 가능합니다.
