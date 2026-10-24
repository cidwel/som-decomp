.setcpu "65816"
.segment "CODE"
.org $26CE
map_control_0d26ce:
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
