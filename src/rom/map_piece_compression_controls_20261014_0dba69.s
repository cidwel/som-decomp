.setcpu "65816"
.segment "CODE"
.org $BA69
map_control_0dba69:
    .byte $E7 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
