.setcpu "65816"
.segment "CODE"
.org $28C8
map_control_0c28c8:
    .byte $E8 ; backreference distance high bits
    .byte $22 ; distance low bit/count
