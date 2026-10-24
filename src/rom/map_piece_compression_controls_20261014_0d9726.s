.setcpu "65816"
.segment "CODE"
.org $9726
map_control_0d9726:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
