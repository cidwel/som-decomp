.setcpu "65816"
.segment "CODE"
.org $8B57
map_control_0d8b57:
    .byte $E3 ; previous-row copy count
    .byte $D1 ; same-value copy count/distance
