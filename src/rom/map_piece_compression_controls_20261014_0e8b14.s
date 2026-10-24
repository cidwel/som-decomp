.setcpu "65816"
.segment "CODE"
.org $8B14
map_control_0e8b14:
    .byte $C5 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
