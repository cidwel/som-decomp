.setcpu "65816"
.segment "CODE"
.org $779A
map_control_0e779a:
    .byte $E6 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
