.setcpu "65816"
.segment "CODE"
.org $F4DD
map_control_0df4dd:
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
