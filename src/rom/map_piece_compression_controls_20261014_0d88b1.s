.setcpu "65816"
.segment "CODE"
.org $88B1
map_control_0d88b1:
    .byte $E7 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
