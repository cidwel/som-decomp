.setcpu "65816"
.segment "CODE"
.org $B21E
map_control_0eb21e:
    .byte $CF ; same-value copy count/distance
    .byte $C3 ; same-value copy count/distance
