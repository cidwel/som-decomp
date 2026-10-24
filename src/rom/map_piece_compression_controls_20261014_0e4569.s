.setcpu "65816"
.segment "CODE"
.org $4569
map_control_0e4569:
    .byte $E6 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
