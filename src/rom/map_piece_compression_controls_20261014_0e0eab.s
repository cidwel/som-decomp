.setcpu "65816"
.segment "CODE"
.org $0EAB
map_control_0e0eab:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
