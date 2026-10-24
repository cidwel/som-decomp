.setcpu "65816"
.segment "CODE"
.org $F553
map_control_0df553:
    .byte $EA ; backreference distance high bits
    .byte $89 ; distance low bit/count
