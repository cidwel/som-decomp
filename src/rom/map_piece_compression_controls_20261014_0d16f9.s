.setcpu "65816"
.segment "CODE"
.org $16F9
map_control_0d16f9:
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
