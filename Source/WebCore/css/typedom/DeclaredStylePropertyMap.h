/*
 * Copyright (C) 2022 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#include "StylePropertyMap.h"
#include <wtf/WeakPtr.h>

namespace WebCore {

class CSSStyleRule;
class StyleRule;

// https://drafts.css-houdini.org/css-typed-om/#declared-stylepropertymap-objects
class DeclaredStylePropertyMap final : public StylePropertyMap {
public:
    static Ref<DeclaredStylePropertyMap> create(CSSStyleRule&);

    Vector<StylePropertyMapEntry> entries(ScriptExecutionContext*) const final;
    unsigned size() const final;

private:
    explicit DeclaredStylePropertyMap(CSSStyleRule&);

    StyleRule* styleRule() const;

    void clear() final;
    RefPtr<CSSValue> propertyValue(CSSPropertyID) const final;
    RefPtr<CSSValue> customPropertyValue(const AtomString&) const final;
    void removeProperty(CSSPropertyID) final;
    void removeCustomProperty(const AtomString&) final;

    WeakPtr<CSSStyleRule> m_ownerRule;
};

} // namespace WebCore
