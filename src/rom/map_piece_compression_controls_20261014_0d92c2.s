.setcpu "65816"
.segment "CODE"
.org $92C2
map_control_0d92c2:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
