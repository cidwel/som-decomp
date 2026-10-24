.setcpu "65816"
.segment "CODE"
.org $8004
map_control_0d8004:
    .byte $CF ; same-value copy count/distance
