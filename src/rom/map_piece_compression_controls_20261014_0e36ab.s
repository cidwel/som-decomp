.setcpu "65816"
.segment "CODE"
.org $36AB
map_control_0e36ab:
    .byte $D7 ; same-value copy count/distance
    .byte $C1 ; same-value copy count/distance
