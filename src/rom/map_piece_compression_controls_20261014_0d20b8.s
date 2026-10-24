.setcpu "65816"
.segment "CODE"
.org $20B8
map_control_0d20b8:
    .byte $C5 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
