.setcpu "65816"
.segment "CODE"
.org $1CCD
map_control_0d1ccd:
    .byte $CF ; same-value copy count/distance
    .byte $C1 ; same-value copy count/distance
