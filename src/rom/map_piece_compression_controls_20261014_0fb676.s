.setcpu "65816"
.segment "CODE"
.org $B676
map_control_0fb676:
    .byte $CF ; same-value copy count/distance
    .byte $C7 ; same-value copy count/distance
