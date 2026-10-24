.setcpu "65816"
.segment "CODE"
.org $45AD
map_control_0c45ad:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
