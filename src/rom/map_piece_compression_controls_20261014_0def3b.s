.setcpu "65816"
.segment "CODE"
.org $EF3B
map_control_0def3b:
    .byte $C1 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
