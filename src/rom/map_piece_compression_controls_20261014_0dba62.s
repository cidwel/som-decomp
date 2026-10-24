.setcpu "65816"
.segment "CODE"
.org $BA62
map_control_0dba62:
    .byte $CF ; same-value copy count/distance
    .byte $C1 ; same-value copy count/distance
