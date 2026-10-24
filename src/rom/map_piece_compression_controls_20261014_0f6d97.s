.setcpu "65816"
.segment "CODE"
.org $6D97
map_control_0f6d97:
    .byte $C1 ; same-value copy count/distance
    .byte $DA ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
