.setcpu "65816"
.segment "CODE"
.org $97DD
map_control_0f97dd:
    .byte $CF ; same-value copy count/distance
    .byte $C5 ; same-value copy count/distance
