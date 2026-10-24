.setcpu "65816"
.segment "CODE"
.org $540A
map_control_0f540a:
    .byte $CF ; same-value copy count/distance
    .byte $C3 ; same-value copy count/distance
