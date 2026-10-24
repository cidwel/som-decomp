.setcpu "65816"
.segment "CODE"
.org $28B5
map_control_0d28b5:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $C4 ; same-value copy count/distance
