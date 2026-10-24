.setcpu "65816"
.segment "CODE"
.org $28D0
map_control_0d28d0:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C6 ; same-value copy count/distance
