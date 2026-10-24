.setcpu "65816"
.segment "CODE"
.org $539C
map_control_0f539c:
    .byte $E5 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
