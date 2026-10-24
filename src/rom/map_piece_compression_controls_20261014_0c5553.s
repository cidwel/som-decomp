.setcpu "65816"
.segment "CODE"
.org $5553
map_control_0c5553:
    .byte $E3 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
