.setcpu "65816"
.segment "CODE"
.org $A340
map_control_0da340:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
