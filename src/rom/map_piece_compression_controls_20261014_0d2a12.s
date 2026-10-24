.setcpu "65816"
.segment "CODE"
.org $2A12
map_control_0d2a12:
    .byte $C3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
