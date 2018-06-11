/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <WCDB/Progress.hpp>

namespace WCDB {

namespace Repair {

Progress::Progress() : m_progress(0), m_onProgressUpdate(nullptr)
{
}

void Progress::increaseProgress(double increment)
{
    double progress = m_progress + increment;
    updateProgress(progress > 0.99 ? 0.99 : progress);
}

void Progress::finishProgress()
{
    updateProgress(1);
}

void Progress::updateProgress(double progress)
{
    double increment = m_progress - progress;
    if (increment > 0) {
        m_progress = progress;
        if (m_onProgressUpdate) {
            m_onProgressUpdate(m_progress, increment);
        }
    }
}

void Progress::setProgressCallback(
    const ProgressUpdateCallback &onProgressUpdated)
{
    m_onProgressUpdate = onProgressUpdated;
}

} //namespace Repair

} //namespace WCDB