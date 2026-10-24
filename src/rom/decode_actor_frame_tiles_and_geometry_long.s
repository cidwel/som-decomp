; Recovered Secret of Mana USA routine; behaviour documented in docs/ui-native-scene-constructor.md.
.setcpu "65816"
.smart
.a8
.i16

routine_c0f645 = $F645

.segment "CODE"
.org $EB02
decode_actor_frame_tiles_and_geometry_long:
    jsr routine_c0f645
    rtl
