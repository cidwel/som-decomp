.setcpu "65816"
.segment "CODE"
.org $11EB
map_control_0f11eb:
    .byte $CF ; same-value copy count/distance
    .byte $C1 ; same-value copy count/distance
