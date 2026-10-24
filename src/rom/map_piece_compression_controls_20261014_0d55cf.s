.setcpu "65816"
.segment "CODE"
.org $55CF
map_control_0d55cf:
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
