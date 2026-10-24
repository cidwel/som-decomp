.setcpu "65816"
.segment "CODE"
.org $FCCA
map_control_0dfcca:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
