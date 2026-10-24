.setcpu "65816"
.segment "CODE"
.org $92AD
map_control_0f92ad:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
