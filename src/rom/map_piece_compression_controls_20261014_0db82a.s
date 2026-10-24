.setcpu "65816"
.segment "CODE"
.org $B82A
map_control_0db82a:
    .byte $CF ; same-value copy count/distance
    .byte $C3 ; same-value copy count/distance
