.setcpu "65816"
.segment "CODE"
.org $A9A6
map_control_0ea9a6:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
