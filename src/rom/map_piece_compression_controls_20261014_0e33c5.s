.setcpu "65816"
.segment "CODE"
.org $33C5
map_control_0e33c5:
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
