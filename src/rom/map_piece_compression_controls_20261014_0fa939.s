.setcpu "65816"
.segment "CODE"
.org $A939
map_control_0fa939:
    .byte $CF ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
