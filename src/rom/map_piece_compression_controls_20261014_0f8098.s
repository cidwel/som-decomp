.setcpu "65816"
.segment "CODE"
.org $8098
map_control_0f8098:
    .byte $CF ; same-value copy count/distance
    .byte $C1 ; same-value copy count/distance
