.setcpu "65816"
.segment "CODE"
.org $EEA3
map_control_0deea3:
    .byte $CF ; same-value copy count/distance
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
