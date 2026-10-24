.setcpu "65816"
.segment "CODE"
.org $5DB0
map_control_0c5db0:
    .byte $E9 ; backreference distance high bits
    .byte $84 ; distance low bit/count
