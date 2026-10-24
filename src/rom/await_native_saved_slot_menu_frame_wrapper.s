; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-loaded-game-slot-descriptions.md.
.setcpu "65816"
.smart
.a8
.i16

await_native_menu_vblank_edge = $28FF

.segment "CODE"
.org $2AEA
await_native_saved_slot_menu_frame_wrapper:
    jsr await_native_menu_vblank_edge
    rtl
