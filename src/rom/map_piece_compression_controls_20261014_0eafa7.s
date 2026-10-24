.setcpu "65816"
.segment "CODE"
.org $AFA7
map_control_0eafa7:
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
