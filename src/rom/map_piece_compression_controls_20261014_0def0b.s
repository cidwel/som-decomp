.setcpu "65816"
.segment "CODE"
.org $EF0B
map_control_0def0b:
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
