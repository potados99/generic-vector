# generic-vector

~~~c
vector_t *v = vector_new();
vector_push_back(v, (bundle_t){.int_v = 1});
~~~

## 개요

C99 호환 타입 제네릭 백터 구현입니다.

아래 타입들을 지원합니다:

~~~c
typedef struct bundle {
bool    bool_v;
short   short_v;
int     int_v;
long    long_v;
char    char_v;
char    *str_v;
void    *any_v;
} bundle_t;
~~~

## 프로젝트 구성

~~~
generic-vector/
    └ include/        → 헤더 파일 모아놓은 폴더입니다.
    └ src/            → 소스 파일 모아놓은 폴더입니다.
    └ test/           → 테스트 소스 파일 모아놓은 폴더입니다.
    └ CMakeLists.txt  → 빌드 설정이 들어있는 파일입니다.
    └ main.c          → 앱의 진입점입니다.
    └ README.md       → 이 문서입니다.
~~~

필요한 파일 아무거나 가져다 쓰시고, 컴파일할 때에 `include` 디렉토리 추가해주세요(gcc면 `-Iinclude`). 

아니면 소스 파일과 헤더 파일은 같은 폴더에 두면 됩니다.

## 사용법

아래는 리스트처럼 사용하는 예시입니다.

~~~c
vector_t *v = vector_new();

vector_push_back(v, (bundle_t){.int_v = 1});
vector_push_back(v, (bundle_t){.int_v = 2});
vector_push_back(v, (bundle_t){.int_v = 3});

for (int i = 0; i < vector_size(v); ++i) {
    printf("%d\n", vector_get(v, i).int_v);
}
~~~

## 장점

메모리 신경 안 써도 되고, 타입 어지간한 것은 다 됩니다. 급할 때나 귀찮을 때에 갖다 쓰세요.

## 단점

이중 연결 리스트 기반이고, 모든 원소가 `struct bundle`이며, 그걸 값 복사로 들고 다니기 때문에 아주 빠르진 않습니다.

과제용으로는 좋습니다 :)