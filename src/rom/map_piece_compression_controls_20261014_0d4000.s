.setcpu "65816"
.segment "CODE"
.org $4000
map_control_0d4000:
    .byte $CF ; same-value copy count/distance
    .byte $C1 ; same-value copy count/distance
