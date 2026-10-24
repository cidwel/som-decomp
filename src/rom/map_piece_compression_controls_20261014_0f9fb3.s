.setcpu "65816"
.segment "CODE"
.org $9FB3
map_control_0f9fb3:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
