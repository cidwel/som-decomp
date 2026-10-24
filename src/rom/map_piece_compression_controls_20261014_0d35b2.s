.setcpu "65816"
.segment "CODE"
.org $35B2
map_control_0d35b2:
    .byte $E1 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
