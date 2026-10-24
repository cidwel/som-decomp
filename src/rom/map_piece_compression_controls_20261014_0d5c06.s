.setcpu "65816"
.segment "CODE"
.org $5C06
map_control_0d5c06:
    .byte $E7 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
