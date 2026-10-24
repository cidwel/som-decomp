.setcpu "65816"
.segment "CODE"
.org $9638
map_control_0e9638:
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
