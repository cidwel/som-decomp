.setcpu "65816"
.segment "CODE"
.org $1504
map_control_0d1504:
    .byte $CF ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
