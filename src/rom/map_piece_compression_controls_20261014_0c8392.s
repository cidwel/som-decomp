.setcpu "65816"
.segment "CODE"
.org $8392
map_control_0c8392:
    .byte $E8 ; backreference distance high bits
    .byte $6D ; distance low bit/count
