.setcpu "65816"
.segment "CODE"
.org $63CC
map_control_0d63cc:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
