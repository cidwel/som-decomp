.setcpu "65816"
.segment "CODE"
.org $F7CA
map_control_0df7ca:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
