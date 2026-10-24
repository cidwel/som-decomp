.setcpu "65816"
.segment "CODE"
.org $3F97
map_control_0f3f97:
    .byte $CF ; same-value copy count/distance
    .byte $C6 ; same-value copy count/distance
