.setcpu "65816"
.segment "CODE"
.org $82B2
map_control_0e82b2:
    .byte $C2 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
