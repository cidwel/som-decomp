.setcpu "65816"
.segment "CODE"
.org $B600
map_control_0fb600:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
