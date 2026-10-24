.setcpu "65816"
.segment "CODE"
.org $6671
map_control_0c6671:
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $16 ; distance low bit/count
