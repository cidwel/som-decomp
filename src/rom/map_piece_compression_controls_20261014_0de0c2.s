.setcpu "65816"
.segment "CODE"
.org $E0C2
map_control_0de0c2:
    .byte $CF ; same-value copy count/distance
    .byte $C2 ; same-value copy count/distance
