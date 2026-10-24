.setcpu "65816"
.segment "CODE"
.org $220C
map_control_0e220c:
    .byte $CF ; same-value copy count/distance
    .byte $C4 ; same-value copy count/distance
