.setcpu "65816"
.segment "CODE"
.org $58DE
map_control_0d58de:
    .byte $C2 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
