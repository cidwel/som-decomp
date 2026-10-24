.setcpu "65816"
.segment "CODE"
.org $5C4E
map_control_0f5c4e:
    .byte $CF ; same-value copy count/distance
    .byte $C1 ; same-value copy count/distance
