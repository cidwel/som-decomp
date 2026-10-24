.setcpu "65816"
.segment "CODE"
.org $8C10
map_control_0d8c10:
    .byte $E6 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
