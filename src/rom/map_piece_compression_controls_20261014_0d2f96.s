.setcpu "65816"
.segment "CODE"
.org $2F96
map_control_0d2f96:
    .byte $D1 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
