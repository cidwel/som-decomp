.setcpu "65816"
.segment "CODE"
.org $17BB
map_control_0f17bb:
    .byte $E6 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
