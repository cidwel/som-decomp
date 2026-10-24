.setcpu "65816"
.segment "CODE"
.org $F49A
map_control_0df49a:
    .byte $ED ; backreference distance high bits
    .byte $09 ; distance low bit/count
