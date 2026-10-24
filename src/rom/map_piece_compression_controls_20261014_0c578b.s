.setcpu "65816"
.segment "CODE"
.org $578B
map_control_0c578b:
    .byte $C2 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $8A ; distance low bit/count
