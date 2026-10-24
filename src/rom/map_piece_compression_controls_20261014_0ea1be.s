.setcpu "65816"
.segment "CODE"
.org $A1BE
map_control_0ea1be:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
