.setcpu "65816"
.segment "CODE"
.org $F91A
map_control_0df91a:
    .byte $F5 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $03 ; distance low bit/count
