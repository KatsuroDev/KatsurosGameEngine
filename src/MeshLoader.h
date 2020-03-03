//
//  MeshLoader.h
//
//  Created by Thomas Lessard on 2020-03-02.
//  Copyright © 2020 Thomas Lessard. All rights reserved.
//

#ifndef MESH_LOADER_H
#define MESH_LOADER_H

#include "Mesh.h"

class MeshLoader
{
public:
    MeshLoader(const MeshLoader&) = delete;

    // Public getter
    static MeshLoader& Get();

    // MeshLoader functions
    static Mesh Load(const char* file);

private:
    // Internal functions
    Mesh InternalLoad(const char* file);

    // Singleton constructor
    MeshLoader();
};

#endif /* MESH_LOADER_H */
