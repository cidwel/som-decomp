.setcpu "65816"
.segment "CODE"
.org $A6B6
map_control_0ea6b6:
    .byte $E8 ; backreference distance high bits
    .byte $28 ; distance low bit/count
