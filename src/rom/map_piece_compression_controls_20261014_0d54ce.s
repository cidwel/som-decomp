.setcpu "65816"
.segment "CODE"
.org $54CE
map_control_0d54ce:
    .byte $C2 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
