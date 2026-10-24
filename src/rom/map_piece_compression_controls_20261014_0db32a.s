.setcpu "65816"
.segment "CODE"
.org $B32A
map_control_0db32a:
    .byte $CF ; same-value copy count/distance
    .byte $C1 ; same-value copy count/distance
