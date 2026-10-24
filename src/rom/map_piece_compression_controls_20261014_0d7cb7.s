.setcpu "65816"
.segment "CODE"
.org $7CB7
map_control_0d7cb7:
    .byte $CF ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
