.setcpu "65816"
.segment "CODE"
.org $9850
map_control_0e9850:
    .byte $EF ; backreference distance high bits
    .byte $07 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
