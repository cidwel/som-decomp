.setcpu "65816"
.segment "CODE"
.org $7167
map_control_0c7167:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
