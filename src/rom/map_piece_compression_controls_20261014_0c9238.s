.setcpu "65816"
.segment "CODE"
.org $9238
map_control_0c9238:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
