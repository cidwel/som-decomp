.setcpu "65816"
.segment "CODE"
.org $BFEF
map_control_0ebfef:
    .byte $E8 ; backreference distance high bits
    .byte $90 ; distance low bit/count
