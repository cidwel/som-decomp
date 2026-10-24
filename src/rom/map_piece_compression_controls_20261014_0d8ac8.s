.setcpu "65816"
.segment "CODE"
.org $8AC8
map_control_0d8ac8:
    .byte $C2 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
