.setcpu "65816"
.segment "CODE"
.org $2A35
map_control_0e2a35:
    .byte $CF ; same-value copy count/distance
    .byte $C7 ; same-value copy count/distance
