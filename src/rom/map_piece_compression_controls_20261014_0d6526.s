.setcpu "65816"
.segment "CODE"
.org $6526
map_control_0d6526:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
