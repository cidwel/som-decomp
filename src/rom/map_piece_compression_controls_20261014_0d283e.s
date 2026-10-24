.setcpu "65816"
.segment "CODE"
.org $283E
map_control_0d283e:
    .byte $CF ; same-value copy count/distance
    .byte $C2 ; same-value copy count/distance
