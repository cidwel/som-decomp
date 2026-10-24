.setcpu "65816"
.segment "CODE"
.org $3940
map_control_0e3940:
    .byte $E4 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
