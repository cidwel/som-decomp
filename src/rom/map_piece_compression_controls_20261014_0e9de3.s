.setcpu "65816"
.segment "CODE"
.org $9DE3
map_control_0e9de3:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
