.setcpu "65816"
.segment "CODE"
.org $3BF9
map_control_0c3bf9:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
