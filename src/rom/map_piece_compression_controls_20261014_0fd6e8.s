.setcpu "65816"
.segment "CODE"
.org $D6E8
map_control_0fd6e8:
    .byte $C6 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E3 ; previous-row copy count
