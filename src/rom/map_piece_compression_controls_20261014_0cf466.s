.setcpu "65816"
.segment "CODE"
.org $F466
map_control_0cf466:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
