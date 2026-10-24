.setcpu "65816"
.segment "CODE"
.org $B218
map_control_0eb218:
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
