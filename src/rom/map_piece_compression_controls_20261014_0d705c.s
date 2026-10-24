.setcpu "65816"
.segment "CODE"
.org $705C
map_control_0d705c:
    .byte $CF ; same-value copy count/distance
    .byte $C4 ; same-value copy count/distance
