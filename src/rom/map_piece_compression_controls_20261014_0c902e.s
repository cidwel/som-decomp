.setcpu "65816"
.segment "CODE"
.org $902E
map_control_0c902e:
    .byte $D5 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
