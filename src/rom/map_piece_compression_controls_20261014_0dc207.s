.setcpu "65816"
.segment "CODE"
.org $C207
map_control_0dc207:
    .byte $E3 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
