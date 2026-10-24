.setcpu "65816"
.segment "CODE"
.org $92AD
map_control_0c92ad:
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
