.setcpu "65816"
.segment "CODE"
.org $EEC8
map_control_0feec8:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
