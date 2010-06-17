#ifndef FACEBOOK_PHOTO_H_
#define FACEBOOK_PHOTO_H_

#include "Common.h"
#include "Object.h"

namespace Facebook
{
	class Photo : public Object
	{
		typedef Object inherited;

	public: // ctor and ~()
		Photo() { }
		virtual ~Photo() { }

	public: // public subclasses
		class From : public Object
		{
		public: // public interface
			void Deserialize(const Json::Value &json);

			const std::string& GetName() const { return name_; }
			const std::string& GetCategory() const { return category_; }
			const std::string& GetId() const { return id_; }

		private: // private members
			std::string name_;
			std::string category_;
			std::string id_;
		};

	public: // public interface
		void Deserialize(const Json::Value &json);

		const std::string& GetId() const { return id_; }
		const From& GetFrom() const { return from_; }
		const std::string& GetName() const { return name_; }
		const std::string& GetPicture() const { return picture_; }
		const std::string& GetSource() const { return source_; }
		unsigned int GetHeight() const { return height_; }
		unsigned int GetWidth() const { return width_; }
		const std::string& GetLink() const { return link_; }
		const std::string& GetIcon() const { return icon_; }
		const std::string& GetCreatedTime() const { return created_time_; }
		const std::string& GetUpdatedTime() const { return updated_time_; }

	private: // private members
		std::string id_;
		From from_;
		std::string name_;
		std::string picture_;
		std::string source_;
		unsigned int height_;
		unsigned int width_;
		std::string link_;
		std::string icon_;
		std::string created_time_;
		std::string updated_time_;
	};
}

#endif // FACEBOOK_PHOTO_H_
