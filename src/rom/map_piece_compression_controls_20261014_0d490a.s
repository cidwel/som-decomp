.setcpu "65816"
.segment "CODE"
.org $490A
map_control_0d490a:
    .byte $E8 ; backreference distance high bits
    .byte $A7 ; distance low bit/count
