.setcpu "65816"
.segment "CODE"
.org $C170
map_control_0fc170:
    .byte $CF ; same-value copy count/distance
    .byte $C6 ; same-value copy count/distance
