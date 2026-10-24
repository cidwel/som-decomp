.setcpu "65816"
.segment "CODE"
.org $10B6
map_control_0c10b6:
    .byte $E2 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
