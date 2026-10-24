.setcpu "65816"
.segment "CODE"
.org $F863
map_control_0df863:
    .byte $F2 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
