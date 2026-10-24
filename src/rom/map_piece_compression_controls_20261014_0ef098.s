.setcpu "65816"
.segment "CODE"
.org $F098
map_control_0ef098:
    .byte $C1 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
