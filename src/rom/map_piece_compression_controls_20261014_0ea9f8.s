.setcpu "65816"
.segment "CODE"
.org $A9F8
map_control_0ea9f8:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
