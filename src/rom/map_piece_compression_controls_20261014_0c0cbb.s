.setcpu "65816"
.segment "CODE"
.org $0CBB
map_control_0c0cbb:
    .byte $F5 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $08 ; distance low bit/count
