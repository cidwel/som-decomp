.setcpu "65816"
.segment "CODE"
.org $91D9
map_control_0c91d9:
    .byte $E8 ; backreference distance high bits
    .byte $A9 ; distance low bit/count
