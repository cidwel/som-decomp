.setcpu "65816"
.segment "CODE"
.org $767C
map_control_0e767c:
    .byte $E6 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
