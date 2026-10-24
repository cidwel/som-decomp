.setcpu "65816"
.segment "CODE"
.org $21F6
map_control_0d21f6:
    .byte $CF ; same-value copy count/distance
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
    .byte $C1 ; same-value copy count/distance
