.setcpu "65816"
.segment "CODE"
.org $21E8
map_control_0d21e8:
    .byte $CF ; same-value copy count/distance
    .byte $C3 ; same-value copy count/distance
