.setcpu "65816"
.segment "CODE"
.org $462E
map_control_0f462e:
    .byte $CF ; same-value copy count/distance
    .byte $C6 ; same-value copy count/distance
