.setcpu "65816"
.segment "CODE"
.org $CF31
map_control_0ecf31:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
