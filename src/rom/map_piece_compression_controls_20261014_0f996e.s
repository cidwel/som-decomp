.setcpu "65816"
.segment "CODE"
.org $996E
map_control_0f996e:
    .byte $E8 ; backreference distance high bits
    .byte $7F ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
