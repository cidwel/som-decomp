.setcpu "65816"
.segment "CODE"
.org $80E4
map_control_0d80e4:
    .byte $CF ; same-value copy count/distance
    .byte $C2 ; same-value copy count/distance
