.setcpu "65816"
.segment "CODE"
.org $7F30
map_control_0d7f30:
    .byte $E2 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
