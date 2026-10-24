.setcpu "65816"
.segment "CODE"
.org $EADF
map_control_0eeadf:
    .byte $E8 ; backreference distance high bits
    .byte $76 ; distance low bit/count
