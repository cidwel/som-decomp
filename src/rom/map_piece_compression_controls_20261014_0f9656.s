.setcpu "65816"
.segment "CODE"
.org $9656
map_control_0f9656:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
