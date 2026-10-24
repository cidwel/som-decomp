.setcpu "65816"
.segment "CODE"
.org $5004
map_control_0c5004:
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
