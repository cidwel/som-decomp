.setcpu "65816"
.segment "CODE"
.org $BEEC
map_control_0ebeec:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
