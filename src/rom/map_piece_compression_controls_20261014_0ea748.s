.setcpu "65816"
.segment "CODE"
.org $A748
map_control_0ea748:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
