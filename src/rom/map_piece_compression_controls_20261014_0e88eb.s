.setcpu "65816"
.segment "CODE"
.org $88EB
map_control_0e88eb:
    .byte $C9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
