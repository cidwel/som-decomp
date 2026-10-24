.setcpu "65816"
.segment "CODE"
.org $D868
map_control_0fd868:
    .byte $E3 ; previous-row copy count
    .byte $CF ; same-value copy count/distance
    .byte $C1 ; same-value copy count/distance
