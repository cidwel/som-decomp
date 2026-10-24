.setcpu "65816"
.segment "CODE"
.org $7886
map_control_0f7886:
    .byte $E2 ; previous-row copy count
    .byte $CF ; same-value copy count/distance
