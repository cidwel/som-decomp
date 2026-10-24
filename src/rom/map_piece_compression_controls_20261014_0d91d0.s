.setcpu "65816"
.segment "CODE"
.org $91D0
map_control_0d91d0:
    .byte $ED ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $38 ; distance low bit/count
