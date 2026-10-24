.setcpu "65816"
.segment "CODE"
.org $7BB2
map_control_0f7bb2:
    .byte $EA ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
