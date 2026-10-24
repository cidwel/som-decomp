.setcpu "65816"
.segment "CODE"
.org $D83F
map_control_0fd83f:
    .byte $CF ; same-value copy count/distance
    .byte $C7 ; same-value copy count/distance
