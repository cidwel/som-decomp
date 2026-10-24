.setcpu "65816"
.segment "CODE"
.org $A831
map_control_0fa831:
    .byte $CF ; same-value copy count/distance
    .byte $C4 ; same-value copy count/distance
