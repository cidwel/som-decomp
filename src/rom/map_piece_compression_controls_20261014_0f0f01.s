.setcpu "65816"
.segment "CODE"
.org $0F01
map_control_0f0f01:
    .byte $CF ; same-value copy count/distance
    .byte $C7 ; same-value copy count/distance
