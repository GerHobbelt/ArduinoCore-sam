#!/bin/bash -ex

#  pack.*.bash - Bash script to help packaging samd core releases.
#  Copyright (c) 2015 Arduino LLC.  All right reserved.
#
#  This library is free software; you can redistribute it and/or
#  modify it under the terms of the GNU Lesser General Public
#  License as published by the Free Software Foundation; either
#  version 2.1 of the License, or (at your option) any later version.
#
#  This library is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#  Lesser General Public License for more details.
#
#  You should have received a copy of the GNU Lesser General Public
#  License along with this library; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

VERSION=`grep version= platform.txt | sed 's/version=//g'`

PWD=`pwd`
FOLDERNAME=`basename $PWD`
THIS_SCRIPT_NAME=`basename $0`

rm -f samd-$VERSION.tar.bz2

cd ..
tar --transform "s|$FOLDERNAME|$FOLDERNAME-$VERSION|g"  --exclude=extras/** --exclude=.git* --exclude=.idea -cjf samd-$VERSION.tar.bz2 $FOLDERNAME
cd -

mv ../samd-$VERSION.tar.bz2 .

echo ""
echo "=========================================="
echo "  Package: samd-$VERSION.tar.bz2"
echo "=========================================="
FILESIZE=$(stat -c%s samd-$VERSION.tar.bz2)
SHA256=$(sha256sum samd-$VERSION.tar.bz2 | awk '{print $1}')
echo "  Size:     $FILESIZE"
echo "  SHA256:   $SHA256"
echo "=========================================="

