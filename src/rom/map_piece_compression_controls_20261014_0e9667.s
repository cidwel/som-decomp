.setcpu "65816"
.segment "CODE"
.org $9667
map_control_0e9667:
    .byte $E8 ; backreference distance high bits
    .byte $8C ; distance low bit/count
