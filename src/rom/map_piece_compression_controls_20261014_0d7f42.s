.setcpu "65816"
.segment "CODE"
.org $7F42
map_control_0d7f42:
    .byte $E7 ; previous-row copy count
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
