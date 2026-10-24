.setcpu "65816"
.segment "CODE"
.org $08F1
map_control_0e08f1:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
