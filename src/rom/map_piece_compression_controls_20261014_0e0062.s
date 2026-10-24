.setcpu "65816"
.segment "CODE"
.org $0062
map_control_0e0062:
    .byte $F1 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
