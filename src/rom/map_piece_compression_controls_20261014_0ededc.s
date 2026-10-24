.setcpu "65816"
.segment "CODE"
.org $DEDC
map_control_0ededc:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
