.setcpu "65816"
.segment "CODE"
.org $2726
map_control_0d2726:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
