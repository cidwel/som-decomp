.setcpu "65816"
.segment "CODE"
.org $3C00
map_control_0c3c00:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
