.setcpu "65816"
.segment "CODE"
.org $45AD
map_control_0d45ad:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
