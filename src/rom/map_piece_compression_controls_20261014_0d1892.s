.setcpu "65816"
.segment "CODE"
.org $1892
map_control_0d1892:
    .byte $E5 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
