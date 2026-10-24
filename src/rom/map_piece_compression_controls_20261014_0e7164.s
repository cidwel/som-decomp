.setcpu "65816"
.segment "CODE"
.org $7164
map_control_0e7164:
    .byte $E6 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
