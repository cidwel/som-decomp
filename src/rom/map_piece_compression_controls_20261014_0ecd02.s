.setcpu "65816"
.segment "CODE"
.org $CD02
map_control_0ecd02:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E1 ; previous-row copy count
    .byte $D3 ; same-value copy count/distance
