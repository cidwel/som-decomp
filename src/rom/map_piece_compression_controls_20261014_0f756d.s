.setcpu "65816"
.segment "CODE"
.org $756D
map_control_0f756d:
    .byte $CF ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
