.setcpu "65816"
.segment "CODE"
.org $27CF
map_control_0d27cf:
    .byte $CF ; same-value copy count/distance
    .byte $C3 ; same-value copy count/distance
