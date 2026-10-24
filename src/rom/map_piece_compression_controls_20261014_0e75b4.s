.setcpu "65816"
.segment "CODE"
.org $75B4
map_control_0e75b4:
    .byte $E1 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
