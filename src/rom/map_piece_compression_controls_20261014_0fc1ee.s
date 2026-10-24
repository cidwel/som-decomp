.setcpu "65816"
.segment "CODE"
.org $C1EE
map_control_0fc1ee:
    .byte $F3 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $08 ; distance low bit/count
