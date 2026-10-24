.setcpu "65816"
.segment "CODE"
.org $1913
map_control_0f1913:
    .byte $E7 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
