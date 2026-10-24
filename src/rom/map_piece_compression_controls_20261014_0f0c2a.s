.setcpu "65816"
.segment "CODE"
.org $0C2A
map_control_0f0c2a:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
