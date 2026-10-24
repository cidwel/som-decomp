.setcpu "65816"
.segment "CODE"
.org $7226
map_control_0d7226:
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $D3 ; same-value copy count/distance
