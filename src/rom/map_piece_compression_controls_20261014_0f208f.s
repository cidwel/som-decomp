.setcpu "65816"
.segment "CODE"
.org $208F
map_control_0f208f:
    .byte $E1 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
