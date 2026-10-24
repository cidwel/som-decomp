.setcpu "65816"
.segment "CODE"
.org $4266
map_control_0f4266:
    .byte $C1 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
