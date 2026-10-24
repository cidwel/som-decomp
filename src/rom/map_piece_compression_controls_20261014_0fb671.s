.setcpu "65816"
.segment "CODE"
.org $B671
map_control_0fb671:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $89 ; distance low bit/count
