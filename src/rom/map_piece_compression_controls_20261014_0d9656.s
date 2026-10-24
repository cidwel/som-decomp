.setcpu "65816"
.segment "CODE"
.org $9656
map_control_0d9656:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
