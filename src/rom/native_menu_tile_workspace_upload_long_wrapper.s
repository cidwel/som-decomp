; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-personality-page.md.
.setcpu "65816"
.smart
.a8
.i16

upload_complete_native_menu_tile_workspace = $25AD

.segment "CODE"
.org $2AD7
native_menu_tile_workspace_upload_long_wrapper:
    jsr upload_complete_native_menu_tile_workspace
    rtl
