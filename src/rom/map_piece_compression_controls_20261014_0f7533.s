.setcpu "65816"
.segment "CODE"
.org $7533
map_control_0f7533:
    .byte $CF ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
