.setcpu "65816"
.segment "CODE"
.org $DD85
map_control_0fdd85:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
