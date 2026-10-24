.setcpu "65816"
.segment "CODE"
.org $48D5
map_control_0d48d5:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
