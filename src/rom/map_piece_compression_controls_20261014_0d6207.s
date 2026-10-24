.setcpu "65816"
.segment "CODE"
.org $6207
map_control_0d6207:
    .byte $E3 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
