.setcpu "65816"
.segment "CODE"
.org $D523
map_control_0fd523:
    .byte $EB ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $40 ; distance low bit/count
