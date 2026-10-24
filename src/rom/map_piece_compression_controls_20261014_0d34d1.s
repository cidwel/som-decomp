.setcpu "65816"
.segment "CODE"
.org $34D1
map_control_0d34d1:
    .byte $CF ; same-value copy count/distance
    .byte $C5 ; same-value copy count/distance
