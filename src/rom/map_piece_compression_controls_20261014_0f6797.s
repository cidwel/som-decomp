.setcpu "65816"
.segment "CODE"
.org $6797
map_control_0f6797:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
