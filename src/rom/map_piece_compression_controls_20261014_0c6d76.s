.setcpu "65816"
.segment "CODE"
.org $6D76
map_control_0c6d76:
    .byte $DA ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
