.setcpu "65816"
.segment "CODE"
.org $29ED
map_control_0d29ed:
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
