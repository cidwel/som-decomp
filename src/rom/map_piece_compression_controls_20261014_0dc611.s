.setcpu "65816"
.segment "CODE"
.org $C611
map_control_0dc611:
    .byte $C4 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
