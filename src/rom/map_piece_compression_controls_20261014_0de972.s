.setcpu "65816"
.segment "CODE"
.org $E972
map_control_0de972:
    .byte $E0 ; previous-row copy escape
    .byte $24 ; row-distance/count
    .byte $CF ; same-value copy count/distance
    .byte $C3 ; same-value copy count/distance
