.setcpu "65816"
.segment "CODE"
.org $21DD
map_control_0e21dd:
    .byte $CF ; same-value copy count/distance
    .byte $C4 ; same-value copy count/distance
