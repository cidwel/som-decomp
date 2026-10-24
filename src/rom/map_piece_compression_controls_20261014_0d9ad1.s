.setcpu "65816"
.segment "CODE"
.org $9AD1
map_control_0d9ad1:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
