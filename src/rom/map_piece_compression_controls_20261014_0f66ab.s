.setcpu "65816"
.segment "CODE"
.org $66AB
map_control_0f66ab:
    .byte $E1 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
