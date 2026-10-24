.setcpu "65816"
.segment "CODE"
.org $622B
map_control_0e622b:
    .byte $EF ; backreference distance high bits
    .byte $19 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $27 ; distance low bit/count
