.setcpu "65816"
.segment "CODE"
.org $380E
map_control_0e380e:
    .byte $CF ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
