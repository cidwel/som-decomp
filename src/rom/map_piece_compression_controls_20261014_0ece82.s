.setcpu "65816"
.segment "CODE"
.org $CE82
map_control_0ece82:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $86 ; distance low bit/count
