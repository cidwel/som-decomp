.setcpu "65816"
.segment "CODE"
.org $6FA2
map_control_0c6fa2:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
