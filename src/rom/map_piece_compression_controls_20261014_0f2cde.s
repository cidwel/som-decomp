.setcpu "65816"
.segment "CODE"
.org $2CDE
map_control_0f2cde:
    .byte $CF ; same-value copy count/distance
    .byte $C7 ; same-value copy count/distance
