/*
 * Copyright (C) 2019 Apple Inc. All rights reserved.
 * Copyright (C) 2019, 2021 Igalia S.L.
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
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "ScrollingTreeScrollingNodeDelegateNicosia.h"

#if ENABLE(ASYNC_SCROLLING) && USE(NICOSIA)

#include "NicosiaPlatformLayer.h"
#include "ScrollingTreeFrameScrollingNode.h"

namespace WebCore {

ScrollingTreeScrollingNodeDelegateNicosia::ScrollingTreeScrollingNodeDelegateNicosia(ScrollingTreeScrollingNode& scrollingNode, bool scrollAnimatorEnabled)
    : ThreadedScrollingTreeScrollingNodeDelegate(scrollingNode)
    , m_scrollAnimatorEnabled(scrollAnimatorEnabled)
{
}

ScrollingTreeScrollingNodeDelegateNicosia::~ScrollingTreeScrollingNodeDelegateNicosia() = default;

void ScrollingTreeScrollingNodeDelegateNicosia::updateVisibleLengths()
{
    m_scrollController.contentsSizeChanged();
}

bool ScrollingTreeScrollingNodeDelegateNicosia::handleWheelEvent(const PlatformWheelEvent& wheelEvent)
{
    auto deferrer = WheelEventTestMonitorCompletionDeferrer { scrollingTree().wheelEventTestMonitor(), reinterpret_cast<WheelEventTestMonitor::ScrollableAreaIdentifier>(scrollingNode().scrollingNodeID()), WheelEventTestMonitor::HandlingWheelEvent };

    updateUserScrollInProgressForEvent(wheelEvent);

    return m_scrollController.handleWheelEvent(wheelEvent);
}

} // namespace WebCore

#endif // ENABLE(ASYNC_SCROLLING) && USE(NICOSIA)
