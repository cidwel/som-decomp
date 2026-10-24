.setcpu "65816"
.segment "CODE"
.org $58A4
map_control_0e58a4:
    .byte $D3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $E8 ; backreference distance high bits
    .byte $13 ; distance low bit/count
