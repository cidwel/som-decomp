.setcpu "65816"
.segment "CODE"
.org $2EE3
map_control_0f2ee3:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
