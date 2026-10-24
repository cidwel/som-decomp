.setcpu "65816"
.segment "CODE"
.org $91ED
map_control_0c91ed:
    .byte $E8 ; backreference distance high bits
    .byte $A9 ; distance low bit/count
