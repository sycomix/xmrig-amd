/* XMRig
 * Copyright 2010      Jeff Garzik <jgarzik@pobox.com>
 * Copyright 2012-2014 pooler      <pooler@litecoinpool.org>
 * Copyright 2014      Lucas Jones <https://github.com/lucasjones>
 * Copyright 2014-2016 Wolf9466    <https://github.com/OhGodAPet>
 * Copyright 2016      Jay D Dee   <jayddee246@gmail.com>
 * Copyright 2017-2018 XMR-Stak    <https://github.com/fireice-uk>, <https://github.com/psychocrypt>
 * Copyright 2016-2018 XMRig       <https://github.com/xmrig>, <support@xmrig.com>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <string.h>


#include "rapidjson/document.h"
#include "workers/OclThread.h"


OclThread::OclThread() :
    m_compMode(true),
    m_memChunk(2),
    m_stridedIndex(1),
    m_affinity(-1),
    m_index(0),
    m_intensity(0),
    m_threadId(0),
    m_worksize(0)
{
}


OclThread::OclThread(size_t index, size_t intensity, size_t worksize, int64_t affinity) :
    m_compMode(true),
    m_memChunk(2),
    m_stridedIndex(1),
    m_affinity(affinity),
    m_index(index),
    m_intensity(intensity),
    m_threadId(0),
    m_worksize(worksize)
{
}


OclThread::~OclThread()
{
}


#ifndef XMRIG_NO_API
rapidjson::Value OclThread::toAPI(rapidjson::Document &doc) const
{
    using namespace rapidjson;

    Value obj(kObjectType);
//    auto &allocator = doc.GetAllocator();

//    obj.AddMember("type",          "cpu", allocator);
//    obj.AddMember("av",             m_av, allocator);
//    obj.AddMember("low_power_mode", multiway(), allocator);
//    obj.AddMember("affine_to_cpu",  affinity(), allocator);
//    obj.AddMember("priority",       priority(), allocator);
//    obj.AddMember("soft_aes",       isSoftAES(), allocator);

    return obj;
}
#endif


rapidjson::Value OclThread::toConfig(rapidjson::Document &doc) const
{
    using namespace rapidjson;

    Value obj(kObjectType);
//    auto &allocator = doc.GetAllocator();

//    obj.AddMember("low_power_mode", multiway(), allocator);
//    obj.AddMember("affine_to_cpu",  affinity() == -1L ? Value(kFalseType) : Value(affinity()), allocator);

    return obj;
}
