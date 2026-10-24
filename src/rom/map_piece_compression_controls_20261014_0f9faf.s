.setcpu "65816"
.segment "CODE"
.org $9FAF
map_control_0f9faf:
    .byte $E3 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
