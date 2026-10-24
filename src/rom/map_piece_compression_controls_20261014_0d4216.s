.setcpu "65816"
.segment "CODE"
.org $4216
map_control_0d4216:
    .byte $E1 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
