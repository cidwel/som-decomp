.setcpu "65816"
.segment "CODE"
.org $5DB6
map_control_0d5db6:
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
