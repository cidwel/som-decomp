.setcpu "65816"
.segment "CODE"
.org $38BB
map_control_0e38bb:
    .byte $C5 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
