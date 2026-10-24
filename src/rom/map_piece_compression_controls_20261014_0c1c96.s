.setcpu "65816"
.segment "CODE"
.org $1C96
map_control_0c1c96:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
