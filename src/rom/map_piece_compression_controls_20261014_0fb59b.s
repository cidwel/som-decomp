.setcpu "65816"
.segment "CODE"
.org $B59B
map_control_0fb59b:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $20 ; distance low bit/count
