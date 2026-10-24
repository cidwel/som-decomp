.setcpu "65816"
.segment "CODE"
.org $7AC6
map_control_0f7ac6:
    .byte $C1 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
