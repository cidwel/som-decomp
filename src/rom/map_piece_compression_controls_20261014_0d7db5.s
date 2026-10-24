.setcpu "65816"
.segment "CODE"
.org $7DB5
map_control_0d7db5:
    .byte $C2 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
