.setcpu "65816"
.segment "CODE"
.org $C18C
map_control_0ec18c:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
