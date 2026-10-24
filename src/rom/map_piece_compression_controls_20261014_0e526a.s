.setcpu "65816"
.segment "CODE"
.org $526A
map_control_0e526a:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $23 ; distance low bit/count
