.setcpu "65816"
.segment "CODE"
.org $FFD7
map_control_0effd7:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
