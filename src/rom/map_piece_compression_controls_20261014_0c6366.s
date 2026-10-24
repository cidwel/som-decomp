.setcpu "65816"
.segment "CODE"
.org $6366
map_control_0c6366:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
