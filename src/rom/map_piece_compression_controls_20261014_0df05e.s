.setcpu "65816"
.segment "CODE"
.org $F05E
map_control_0df05e:
    .byte $E4 ; previous-row copy count
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
