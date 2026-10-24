.setcpu "65816"
.segment "CODE"
.org $B49C
map_control_0eb49c:
    .byte $EC ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
