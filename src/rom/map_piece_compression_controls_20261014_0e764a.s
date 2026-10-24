.setcpu "65816"
.segment "CODE"
.org $764A
map_control_0e764a:
    .byte $F1 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $8B ; distance low bit/count
