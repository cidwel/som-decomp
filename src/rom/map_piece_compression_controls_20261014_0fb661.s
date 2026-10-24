.setcpu "65816"
.segment "CODE"
.org $B661
map_control_0fb661:
    .byte $CF ; same-value copy count/distance
    .byte $C7 ; same-value copy count/distance
