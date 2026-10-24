.setcpu "65816"
.segment "CODE"
.org $F611
map_control_0ef611:
    .byte $CF ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
