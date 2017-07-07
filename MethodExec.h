template <typename T>
class MethodExec {
public:
	MethodExec(MethodExec<T>(T::*f)()) : func_(f) {};
	MethodExec<T> exec(T* obj) {
		return (obj->*func_)();
	}
private:
	MethodExec<T>(T::*func_)(); // ���s����T�^�N���X�̃��\�b�h�|�C���^
};
