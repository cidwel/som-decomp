.setcpu "65816"
.segment "CODE"
.org $590D
map_control_0f590d:
    .byte $EA ; backreference distance high bits
    .byte $05 ; distance low bit/count
    .byte $E6 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
