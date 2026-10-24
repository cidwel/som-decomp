.setcpu "65816"
.segment "CODE"
.org $634C
map_control_0c634c:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
