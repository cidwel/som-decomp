.setcpu "65816"
.segment "CODE"
.org $4D1B
map_control_0f4d1b:
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
