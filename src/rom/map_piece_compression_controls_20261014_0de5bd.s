.setcpu "65816"
.segment "CODE"
.org $E5BD
map_control_0de5bd:
    .byte $C4 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
