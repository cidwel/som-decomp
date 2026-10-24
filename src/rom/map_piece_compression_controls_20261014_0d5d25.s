.setcpu "65816"
.segment "CODE"
.org $5D25
map_control_0d5d25:
    .byte $C1 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E7 ; previous-row copy count
