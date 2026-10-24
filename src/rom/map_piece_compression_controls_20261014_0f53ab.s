.setcpu "65816"
.segment "CODE"
.org $53AB
map_control_0f53ab:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
