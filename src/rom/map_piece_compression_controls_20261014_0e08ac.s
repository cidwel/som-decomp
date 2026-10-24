.setcpu "65816"
.segment "CODE"
.org $08AC
map_control_0e08ac:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
