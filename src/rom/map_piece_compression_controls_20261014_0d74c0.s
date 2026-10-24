.setcpu "65816"
.segment "CODE"
.org $74C0
map_control_0d74c0:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
