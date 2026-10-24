.setcpu "65816"
.segment "CODE"
.org $48E0
map_control_0f48e0:
    .byte $C1 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
