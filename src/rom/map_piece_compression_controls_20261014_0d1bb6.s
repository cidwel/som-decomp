.setcpu "65816"
.segment "CODE"
.org $1BB6
map_control_0d1bb6:
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
