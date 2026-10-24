.setcpu "65816"
.segment "CODE"
.org $FD43
map_control_0efd43:
    .byte $E7 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
