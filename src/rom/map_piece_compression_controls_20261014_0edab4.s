.setcpu "65816"
.segment "CODE"
.org $DAB4
map_control_0edab4:
    .byte $D1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D2 ; same-value copy count/distance
