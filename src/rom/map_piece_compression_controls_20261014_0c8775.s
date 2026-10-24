.setcpu "65816"
.segment "CODE"
.org $8775
map_control_0c8775:
    .byte $CF ; same-value copy count/distance
    .byte $C2 ; same-value copy count/distance
