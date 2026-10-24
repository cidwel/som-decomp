.setcpu "65816"
.segment "CODE"
.org $7898
map_control_0e7898:
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
