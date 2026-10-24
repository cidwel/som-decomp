.setcpu "65816"
.segment "CODE"
.org $0CC1
map_control_0c0cc1:
    .byte $F5 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $08 ; distance low bit/count
