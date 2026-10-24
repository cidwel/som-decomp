.setcpu "65816"
.segment "CODE"
.org $2F8D
map_control_0d2f8d:
    .byte $C3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
