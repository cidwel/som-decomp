.setcpu "65816"
.segment "CODE"
.org $AF3B
map_control_0faf3b:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
    .byte $CF ; same-value copy count/distance
