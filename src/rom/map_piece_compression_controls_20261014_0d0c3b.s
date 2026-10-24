.setcpu "65816"
.segment "CODE"
.org $0C3B
map_control_0d0c3b:
    .byte $CF ; same-value copy count/distance
    .byte $C1 ; same-value copy count/distance
