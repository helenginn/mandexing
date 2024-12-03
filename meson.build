project('mandexing', 'cpp')
qt6 = import('qt6')
qt6_dep = dependency('qt6', modules: ['Core', 'Gui', 'Widgets'])
png_dep = dependency('libpng')

moc_files = qt6.preprocess(moc_headers : ['Dialogue.h', 'PredictionView.h', 'Tinker.h'],
                           moc_extra_arguments: ['-DMAKES_MY_MOC_HEADER_COMPILE'])

executable('mandexing', 'Crystal.cpp', 'CSV.cpp', 'Detector.cpp', 'Dialogue.cpp', 'FileReader.cpp', 'main.cpp', 'mat3x3.cpp', 'Node.cpp', 'PNGFile.cpp', 'PredictionView.cpp', 'RefinementGridSearch.cpp', 'RefinementNelderMead.cpp', 'RefinementStepSearch.cpp', 'RefinementStrategy.cpp', 'TextManager.cpp', 'Tinker.cpp', 'vec3.cpp', moc_files, cpp_args: ['-std=c++17', '-mmacosx-version-min=10.15', '-stdlib=libc++'], dependencies: [qt6_dep, png_dep])

#

