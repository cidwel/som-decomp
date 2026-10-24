.setcpu "65816"
.segment "CODE"
.org $7B38
map_control_0e7b38:
    .byte $EE ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0A ; distance low bit/count
