.setcpu "65816"
.segment "CODE"
.org $1C57
map_control_0e1c57:
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
