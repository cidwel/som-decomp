.setcpu "65816"
.segment "CODE"
.org $5233
map_control_0d5233:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
