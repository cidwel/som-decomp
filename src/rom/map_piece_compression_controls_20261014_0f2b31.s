.setcpu "65816"
.segment "CODE"
.org $2B31
map_control_0f2b31:
    .byte $C1 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
