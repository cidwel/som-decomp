.setcpu "65816"
.segment "CODE"
.org $0280
map_control_0f0280:
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
