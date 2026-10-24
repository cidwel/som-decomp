.setcpu "65816"
.segment "CODE"
.org $AF6F
map_control_0eaf6f:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
