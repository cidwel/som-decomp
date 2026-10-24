.setcpu "65816"
.segment "CODE"
.org $97F5
map_control_0f97f5:
    .byte $CF ; same-value copy count/distance
    .byte $C5 ; same-value copy count/distance
