.setcpu "65816"
.segment "CODE"
.org $9AB3
map_control_0e9ab3:
    .byte $C4 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $CF ; same-value copy count/distance
