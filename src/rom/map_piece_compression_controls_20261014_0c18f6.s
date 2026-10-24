.setcpu "65816"
.segment "CODE"
.org $18F6
map_control_0c18f6:
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
