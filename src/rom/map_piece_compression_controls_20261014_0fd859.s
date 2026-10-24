.setcpu "65816"
.segment "CODE"
.org $D859
map_control_0fd859:
    .byte $C6 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
