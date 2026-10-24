.setcpu "65816"
.segment "CODE"
.org $CE2E
map_control_0ece2e:
    .byte $E0 ; previous-row copy escape
    .byte $C1 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
    .byte $C5 ; same-value copy count/distance
