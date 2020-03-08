//
//  MeshLoader.cpp
//
//  Created by Thomas Lessard on 2020-03-02.
//  Copyright © 2020 Thomas Lessard. All rights reserved.
//

#include "MeshLoader.h"

// public getter
MeshLoader& MeshLoader::Get()
{
    static MeshLoader instance;
    return instance;
}

// MeshLoader functions
Mesh MeshLoader::Load(const char* file) { return MeshLoader::Get().MeshLoader::InternalLoad(file); }

// Internal functions
Mesh MeshLoader::InternalLoad(const char* file)
{
    // TODO:
    // Load and create Mesh
    return Mesh();
}

// Singleton constructor (private)
MeshLoader::MeshLoader()
{
}
