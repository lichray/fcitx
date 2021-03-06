if (ENABLE_TABLE)
    add_subdirectory(table)
endif (ENABLE_TABLE)

add_subdirectory(script)
add_subdirectory(icon)

set(FCITX_DESC_FILES
    addon.desc
    config.desc
    profile.desc
    inputmethod.desc
)

set(FCITX_DATA_FILES
    AutoEng.dat
    gbks2t.tab
    punc.mb.zh_CN
    punc.mb.zh_HK
    punc.mb.zh_TW
    vk.conf
    ${CMAKE_CURRENT_BINARY_DIR}/en_dict.fscd
)

set(FCITX_PY_FILES
    pySym.mb
    sp.dat
)

set(FCITX_DSEKTOP_FILES
    fcitx.desktop
    fcitx-configtool.desktop
    fcitx-autostart.desktop
)

set(PY_ORGDATA pyPhrase.org)
set(PY_DATA ${CMAKE_CURRENT_BINARY_DIR}/pybase.mb ${CMAKE_CURRENT_BINARY_DIR}/pyphrase.mb)
set(PY_TAR ${CMAKE_CURRENT_SOURCE_DIR}/pinyin.tar.gz)
set(PY_URL http://fcitx.googlecode.com/files/pinyin.tar.gz)


intltool_merge_translation(${CMAKE_CURRENT_SOURCE_DIR}/fcitx-configtool.desktop.in ${CMAKE_CURRENT_BINARY_DIR}/fcitx-configtool.desktop )
intltool_merge_translation(${CMAKE_CURRENT_SOURCE_DIR}/fcitx.desktop.in ${CMAKE_CURRENT_BINARY_DIR}/fcitx.desktop )
intltool_merge_translation(${CMAKE_CURRENT_SOURCE_DIR}/fcitx-autostart.desktop.in ${CMAKE_CURRENT_BINARY_DIR}/fcitx-autostart.desktop )

add_custom_target(pinyin_data ALL DEPENDS ${PY_DATA})

add_custom_command(OUTPUT ${PY_ORGDATA}
                   COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/download.sh "${WGET}" "${PY_URL}" "${PY_TAR}"
                   COMMAND ${TAR} xzmvf ${PY_TAR})
add_custom_command(OUTPUT ${PY_DATA}
                   DEPENDS ${PY_ORGDATA}
                   COMMAND createPYMB ${CMAKE_CURRENT_SOURCE_DIR}/gbkpy.org ${CMAKE_CURRENT_BINARY_DIR}/${PY_ORGDATA})

add_custom_target(desktopfile ALL DEPENDS ${FCITX_DSEKTOP_FILES})
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/fcitx.desktop DESTINATION share/applications/)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/fcitx-configtool.desktop DESTINATION share/applications/)

install(FILES ${FCITX_DATA_FILES} DESTINATION ${pkgdatadir}/data)
fcitx_add_configdesc_file(${FCITX_DESC_FILES})
install(FILES ${FCITX_PY_FILES} ${CMAKE_CURRENT_BINARY_DIR}/pybase.mb ${CMAKE_CURRENT_BINARY_DIR}/pyphrase.mb DESTINATION ${pkgdatadir}/pinyin)

set_directory_properties(PROPERTIES ADDITIONAL_MAKE_CLEAN_FILES "${CMAKE_CURRENT_BINARY_DIR}/pyERROR,${CMAKE_CURRENT_BINARY_DIR}/pyPhrase.ok")

if (_ENABLE_DBUS AND ENABLE_XDGAUTOSTART)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/fcitx-autostart.desktop DESTINATION /etc/xdg/autostart)
endif (_ENABLE_DBUS AND ENABLE_XDGAUTOSTART)

if (_ENABLE_DBUS)
install(FILES daemon.conf DESTINATION share/fcitx/dbus/)
endif (_ENABLE_DBUS)

set(SPELL_EN_DICT_VER 20120815)
set(SPELL_EN_DICT en_dict.fscd)
set(SPELL_EN_DICT_SRC en_dict.txt)
set(SPELL_EN_DICT_TAR ${CMAKE_CURRENT_SOURCE_DIR}/en_dict-${SPELL_EN_DICT_VER}.tar.gz)
set(SPELL_EN_DICT_URL
    https://github.com/downloads/fcitx/fcitx/en_dict-${SPELL_EN_DICT_VER}.tar.gz)

add_custom_target(spell_en_dict ALL DEPENDS ${SPELL_EN_DICT})
add_custom_command(
  OUTPUT ${SPELL_EN_DICT_SRC}
  COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/download.sh "${WGET}"
  "${SPELL_EN_DICT_URL}" "${SPELL_EN_DICT_TAR}"
  COMMAND "${TAR}" xzmvf "${SPELL_EN_DICT_TAR}")

set(COMP_SPELL_DICT
  "${PROJECT_BINARY_DIR}/src/module/spell/dict/comp-spell-dict")
add_custom_command(
  OUTPUT ${SPELL_EN_DICT}
  DEPENDS ${SPELL_EN_DICT_SRC} "${COMP_SPELL_DICT}"
  COMMAND "${COMP_SPELL_DICT}" "${SPELL_EN_DICT_SRC}" "${SPELL_EN_DICT}")
