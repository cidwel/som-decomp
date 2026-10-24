.setcpu "65816"
.segment "CODE"
.org $78EC
map_control_0c78ec:
    .byte $D1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
