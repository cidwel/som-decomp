.setcpu "65816"
.segment "CODE"
.org $8660
map_control_0c8660:
    .byte $ED ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
