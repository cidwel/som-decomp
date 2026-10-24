.setcpu "65816"
.segment "CODE"
.org $07AE
map_control_0e07ae:
    .byte $CF ; same-value copy count/distance
    .byte $C4 ; same-value copy count/distance
