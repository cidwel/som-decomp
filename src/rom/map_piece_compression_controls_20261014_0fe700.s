.setcpu "65816"
.segment "CODE"
.org $E700
map_control_0fe700:
    .byte $C1 ; same-value copy count/distance
    .byte $DB ; same-value copy count/distance
