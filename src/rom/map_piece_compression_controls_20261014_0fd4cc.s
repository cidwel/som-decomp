.setcpu "65816"
.segment "CODE"
.org $D4CC
map_control_0fd4cc:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
