.setcpu "65816"
.segment "CODE"
.org $479C
map_control_0d479c:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
