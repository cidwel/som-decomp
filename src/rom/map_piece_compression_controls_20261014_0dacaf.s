.setcpu "65816"
.segment "CODE"
.org $ACAF
map_control_0dacaf:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
