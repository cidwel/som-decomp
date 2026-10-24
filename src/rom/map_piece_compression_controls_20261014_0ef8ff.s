.setcpu "65816"
.segment "CODE"
.org $F8FF
map_control_0ef8ff:
    .byte $F2 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
