.setcpu "65816"
.segment "CODE"
.org $88FA
map_control_0d88fa:
    .byte $CF ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
