.setcpu "65816"
.segment "CODE"
.org $D895
map_control_0fd895:
    .byte $C5 ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E3 ; previous-row copy count
