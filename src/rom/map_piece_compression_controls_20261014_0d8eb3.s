.setcpu "65816"
.segment "CODE"
.org $8EB3
map_control_0d8eb3:
    .byte $E3 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
