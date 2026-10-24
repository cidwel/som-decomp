.setcpu "65816"
.segment "CODE"
.org $57B9
map_control_0e57b9:
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
