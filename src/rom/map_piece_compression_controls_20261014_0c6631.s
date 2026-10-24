.setcpu "65816"
.segment "CODE"
.org $6631
map_control_0c6631:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
