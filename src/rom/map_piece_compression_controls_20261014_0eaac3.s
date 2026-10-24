.setcpu "65816"
.segment "CODE"
.org $AAC3
map_control_0eaac3:
    .byte $CF ; same-value copy count/distance
    .byte $C1 ; same-value copy count/distance
