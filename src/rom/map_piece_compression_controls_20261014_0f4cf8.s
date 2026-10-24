.setcpu "65816"
.segment "CODE"
.org $4CF8
map_control_0f4cf8:
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
