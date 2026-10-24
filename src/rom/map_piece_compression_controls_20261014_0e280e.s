.setcpu "65816"
.segment "CODE"
.org $280E
map_control_0e280e:
    .byte $E3 ; previous-row copy count
    .byte $CF ; same-value copy count/distance
    .byte $C4 ; same-value copy count/distance
