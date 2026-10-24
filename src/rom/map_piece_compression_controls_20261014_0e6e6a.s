.setcpu "65816"
.segment "CODE"
.org $6E6A
map_control_0e6e6a:
    .byte $D2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
