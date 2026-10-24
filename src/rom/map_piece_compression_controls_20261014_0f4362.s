.setcpu "65816"
.segment "CODE"
.org $4362
map_control_0f4362:
    .byte $C3 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
