; docs/ui-native-focus-map-bridge.md
.setcpu "65816"
.segment "CODE"
.org $8260
enter_native_map_from_selected_ui_target_index:
    jsr $8223
    jmp $B03F
