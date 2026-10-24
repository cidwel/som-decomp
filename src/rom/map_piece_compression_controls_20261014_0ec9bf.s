.setcpu "65816"
.segment "CODE"
.org $C9BF
map_control_0ec9bf:
    .byte $E8 ; backreference distance high bits
    .byte $A2 ; distance low bit/count
