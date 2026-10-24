.setcpu "65816"
.segment "CODE"
.org $1A48
map_control_0d1a48:
    .byte $CF ; same-value copy count/distance
    .byte $C2 ; same-value copy count/distance
