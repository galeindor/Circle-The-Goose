#file (MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/resources)

configure_file ("duck.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("loseScreen.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("winScreen.png" ${CMAKE_BINARY_DIR} COPYONLY)
configure_file ("font.ttf" ${CMAKE_BINARY_DIR} COPYONLY)
#configure_file ("my_file2.jpg" ${CMAKE_BINARY_DIR}/resources COPYONLY)
