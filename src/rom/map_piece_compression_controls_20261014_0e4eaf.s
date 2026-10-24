.setcpu "65816"
.segment "CODE"
.org $4EAF
map_control_0e4eaf:
    .byte $CF ; same-value copy count/distance
    .byte $C1 ; same-value copy count/distance
