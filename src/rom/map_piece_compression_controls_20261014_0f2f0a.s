.setcpu "65816"
.segment "CODE"
.org $2F0A
map_control_0f2f0a:
    .byte $D7 ; same-value copy count/distance
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
    .byte $E1 ; previous-row copy count
