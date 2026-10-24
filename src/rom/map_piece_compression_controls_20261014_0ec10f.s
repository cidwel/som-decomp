.setcpu "65816"
.segment "CODE"
.org $C10F
map_control_0ec10f:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
