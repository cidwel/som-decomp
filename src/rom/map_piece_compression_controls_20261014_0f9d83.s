.setcpu "65816"
.segment "CODE"
.org $9D83
map_control_0f9d83:
    .byte $CF ; same-value copy count/distance
    .byte $C4 ; same-value copy count/distance
