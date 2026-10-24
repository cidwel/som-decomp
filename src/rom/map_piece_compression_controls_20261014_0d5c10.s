.setcpu "65816"
.segment "CODE"
.org $5C10
map_control_0d5c10:
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
