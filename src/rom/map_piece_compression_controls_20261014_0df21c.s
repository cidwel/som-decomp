.setcpu "65816"
.segment "CODE"
.org $F21C
map_control_0df21c:
    .byte $C2 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $12 ; distance low bit/count
