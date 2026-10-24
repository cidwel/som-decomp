.setcpu "65816"
.segment "CODE"
.org $8CD6
map_control_0f8cd6:
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
