.setcpu "65816"
.segment "CODE"
.org $A4E0
map_control_0ea4e0:
    .byte $C1 ; same-value copy count/distance
    .byte $DB ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
