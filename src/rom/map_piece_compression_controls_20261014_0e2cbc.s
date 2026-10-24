.setcpu "65816"
.segment "CODE"
.org $2CBC
map_control_0e2cbc:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
