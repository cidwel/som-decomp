.setcpu "65816"
.segment "CODE"
.org $8181
map_control_0c8181:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $8F ; distance low bit/count
