.setcpu "65816"
.segment "CODE"
.org $E8A4
map_control_0de8a4:
    .byte $C5 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
