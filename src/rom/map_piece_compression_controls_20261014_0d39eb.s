.setcpu "65816"
.segment "CODE"
.org $39EB
map_control_0d39eb:
    .byte $EF ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
