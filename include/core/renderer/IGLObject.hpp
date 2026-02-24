#pragma once

namespace core::renderer {
class IGLObject {
public:
	virtual void bind() const = 0;
	virtual void unbind() const = 0;
	virtual ~IGLObject() = default;
};
}; //namespace core::renderer