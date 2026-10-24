.setcpu "65816"
.segment "CODE"
.org $4E25
map_control_0f4e25:
    .byte $E1 ; previous-row copy count
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
