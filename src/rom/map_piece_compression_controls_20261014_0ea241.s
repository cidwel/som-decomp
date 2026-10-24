.setcpu "65816"
.segment "CODE"
.org $A241
map_control_0ea241:
    .byte $E8 ; backreference distance high bits
    .byte $0B ; distance low bit/count
