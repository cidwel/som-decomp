.setcpu "65816"
.segment "CODE"
.org $F94C
map_control_0df94c:
    .byte $F2 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
