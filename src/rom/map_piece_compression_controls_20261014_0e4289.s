.setcpu "65816"
.segment "CODE"
.org $4289
map_control_0e4289:
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
