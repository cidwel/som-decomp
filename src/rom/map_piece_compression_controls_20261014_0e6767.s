.setcpu "65816"
.segment "CODE"
.org $6767
map_control_0e6767:
    .byte $E8 ; backreference distance high bits
    .byte $3A ; distance low bit/count
