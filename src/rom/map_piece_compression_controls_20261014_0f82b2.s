.setcpu "65816"
.segment "CODE"
.org $82B2
map_control_0f82b2:
    .byte $D1 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E3 ; previous-row copy count
