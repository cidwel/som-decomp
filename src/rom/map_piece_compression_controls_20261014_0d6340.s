.setcpu "65816"
.segment "CODE"
.org $6340
map_control_0d6340:
    .byte $E4 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
