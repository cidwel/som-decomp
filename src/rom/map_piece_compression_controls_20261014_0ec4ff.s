.setcpu "65816"
.segment "CODE"
.org $C4FF
map_control_0ec4ff:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
