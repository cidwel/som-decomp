.setcpu "65816"
.segment "CODE"
.org $46EC
map_control_0d46ec:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
