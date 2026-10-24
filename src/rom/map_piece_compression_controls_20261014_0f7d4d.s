.setcpu "65816"
.segment "CODE"
.org $7D4D
map_control_0f7d4d:
    .byte $C2 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
