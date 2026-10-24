.setcpu "65816"
.segment "CODE"
.org $4775
map_control_0f4775:
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $40 ; distance low bit/count
