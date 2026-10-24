.setcpu "65816"
.segment "CODE"
.org $28E8
map_control_0f28e8:
    .byte $E8 ; backreference distance high bits
    .byte $40 ; distance low bit/count
