.setcpu "65816"
.segment "CODE"
.org $D70F
map_control_0ed70f:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $35 ; distance low bit/count
