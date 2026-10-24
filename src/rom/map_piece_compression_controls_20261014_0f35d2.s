.setcpu "65816"
.segment "CODE"
.org $35D2
map_control_0f35d2:
    .byte $CF ; same-value copy count/distance
    .byte $C2 ; same-value copy count/distance
