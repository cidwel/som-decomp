.setcpu "65816"
.segment "CODE"
.org $2104
map_control_0c2104:
    .byte $F1 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
