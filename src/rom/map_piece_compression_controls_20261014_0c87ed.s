.setcpu "65816"
.segment "CODE"
.org $87ED
map_control_0c87ed:
    .byte $CF ; same-value copy count/distance
    .byte $C2 ; same-value copy count/distance
