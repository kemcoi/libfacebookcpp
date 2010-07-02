namespace Facebook
{

class Blob
{
public: // ctor and ~()
	Blob() : data_(NULL), bytes_(0)
	{
	}

	~Blob()
	{
		free(data_);
		data_ = NULL;
		bytes_ = 0;
	}

public: // public interface
	const void* GetData() const { return data_; }
	void* GetData() { return data_; }
	size_t GetBytes() const { return bytes_; }

	void Alloc(size_t bytes)
	{
		void *new_data = realloc(data_, bytes);

		if(!new_data)
			// Exception for out of memory
			throw std::exception();

		data_ = new_data;
		bytes_= bytes;
	}

private: // member variables
	void *data_;
	size_t bytes_;
};

} // namespace Facebook