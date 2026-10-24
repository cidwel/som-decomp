.setcpu "65816"
.segment "CODE"
.org $A175
map_control_0ea175:
    .byte $CF ; same-value copy count/distance
    .byte $C3 ; same-value copy count/distance
