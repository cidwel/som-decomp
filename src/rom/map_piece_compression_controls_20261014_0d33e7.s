.setcpu "65816"
.segment "CODE"
.org $33E7
map_control_0d33e7:
    .byte $D1 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
