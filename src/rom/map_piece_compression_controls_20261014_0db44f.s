.setcpu "65816"
.segment "CODE"
.org $B44F
map_control_0db44f:
    .byte $CF ; same-value copy count/distance
    .byte $C1 ; same-value copy count/distance
