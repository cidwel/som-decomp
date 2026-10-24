.setcpu "65816"
.segment "CODE"
.org $779D
map_control_0e779d:
    .byte $E4 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
