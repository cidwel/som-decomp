.setcpu "65816"
.segment "CODE"
.org $E804
map_control_0fe804:
    .byte $CF ; same-value copy count/distance
    .byte $C2 ; same-value copy count/distance
