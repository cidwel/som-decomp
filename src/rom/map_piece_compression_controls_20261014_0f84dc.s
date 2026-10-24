.setcpu "65816"
.segment "CODE"
.org $84DC
map_control_0f84dc:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
