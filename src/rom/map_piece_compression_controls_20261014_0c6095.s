.setcpu "65816"
.segment "CODE"
.org $6095
map_control_0c6095:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
