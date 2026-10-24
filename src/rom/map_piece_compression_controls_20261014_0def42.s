.setcpu "65816"
.segment "CODE"
.org $EF42
map_control_0def42:
    .byte $EA ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E5 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $DF ; same-value copy count/distance
