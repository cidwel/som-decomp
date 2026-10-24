.setcpu "65816"
.segment "CODE"
.org $ACCE
map_control_0dacce:
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
