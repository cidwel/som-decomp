.setcpu "65816"
.segment "CODE"
.org $A379
map_control_0fa379:
    .byte $CF ; same-value copy count/distance
    .byte $C5 ; same-value copy count/distance
