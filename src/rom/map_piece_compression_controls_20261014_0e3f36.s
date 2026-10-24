.setcpu "65816"
.segment "CODE"
.org $3F36
map_control_0e3f36:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
