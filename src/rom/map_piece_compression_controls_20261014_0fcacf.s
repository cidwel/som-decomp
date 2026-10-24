.setcpu "65816"
.segment "CODE"
.org $CACF
map_control_0fcacf:
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
