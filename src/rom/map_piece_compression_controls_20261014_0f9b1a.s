.setcpu "65816"
.segment "CODE"
.org $9B1A
map_control_0f9b1a:
    .byte $D2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
