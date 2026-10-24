.setcpu "65816"
.segment "CODE"
.org $0452
map_control_0f0452:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
