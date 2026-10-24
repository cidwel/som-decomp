.setcpu "65816"
.segment "CODE"
.org $FB19
map_control_0cfb19:
    .byte $CF ; same-value copy count/distance
    .byte $C7 ; same-value copy count/distance
