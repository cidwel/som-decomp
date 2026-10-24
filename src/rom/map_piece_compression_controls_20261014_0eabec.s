.setcpu "65816"
.segment "CODE"
.org $ABEC
map_control_0eabec:
    .byte $E8 ; backreference distance high bits
    .byte $76 ; distance low bit/count
