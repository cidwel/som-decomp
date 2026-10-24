.setcpu "65816"
.segment "CODE"
.org $9992
map_control_0d9992:
    .byte $E6 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
