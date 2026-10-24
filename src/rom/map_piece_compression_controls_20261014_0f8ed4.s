.setcpu "65816"
.segment "CODE"
.org $8ED4
map_control_0f8ed4:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $09 ; distance low bit/count
