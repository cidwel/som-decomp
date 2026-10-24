.setcpu "65816"
.segment "CODE"
.org $CF27
map_control_0fcf27:
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
