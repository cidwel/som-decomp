.setcpu "65816"
.segment "CODE"
.org $E814
map_control_0fe814:
    .byte $CF ; same-value copy count/distance
    .byte $C2 ; same-value copy count/distance
