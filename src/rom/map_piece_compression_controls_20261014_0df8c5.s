.setcpu "65816"
.segment "CODE"
.org $F8C5
map_control_0df8c5:
    .byte $F2 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
