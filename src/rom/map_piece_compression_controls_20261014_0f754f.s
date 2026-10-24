.setcpu "65816"
.segment "CODE"
.org $754F
map_control_0f754f:
    .byte $CF ; same-value copy count/distance
    .byte $C4 ; same-value copy count/distance
