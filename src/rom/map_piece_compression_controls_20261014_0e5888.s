.setcpu "65816"
.segment "CODE"
.org $5888
map_control_0e5888:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
