.setcpu "65816"
.segment "CODE"
.org $EDFB
map_control_0eedfb:
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
