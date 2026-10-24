.setcpu "65816"
.segment "CODE"
.org $723A
map_control_0c723a:
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
