.setcpu "65816"
.segment "CODE"
.org $4AE6
map_control_0e4ae6:
    .byte $F1 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $91 ; distance low bit/count
