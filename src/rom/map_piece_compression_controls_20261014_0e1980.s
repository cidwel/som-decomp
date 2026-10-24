.setcpu "65816"
.segment "CODE"
.org $1980
map_control_0e1980:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
