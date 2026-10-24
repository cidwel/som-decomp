.setcpu "65816"
.segment "CODE"
.org $441A
map_control_0d441a:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
