.setcpu "65816"
.segment "CODE"
.org $4FA3
map_control_0d4fa3:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
