.setcpu "65816"
.segment "CODE"
.org $960F
map_control_0e960f:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
