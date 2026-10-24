.setcpu "65816"
.segment "CODE"
.org $5238
map_control_0c5238:
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
