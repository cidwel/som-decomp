.setcpu "65816"
.segment "CODE"
.org $B0C5
map_control_0fb0c5:
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
