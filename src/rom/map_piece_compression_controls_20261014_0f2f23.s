.setcpu "65816"
.segment "CODE"
.org $2F23
map_control_0f2f23:
    .byte $CF ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
