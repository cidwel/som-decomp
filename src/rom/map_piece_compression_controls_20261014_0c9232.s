.setcpu "65816"
.segment "CODE"
.org $9232
map_control_0c9232:
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
