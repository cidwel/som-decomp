.setcpu "65816"
.segment "CODE"
.org $8153
map_control_0d8153:
    .byte $CF ; same-value copy count/distance
    .byte $C2 ; same-value copy count/distance
