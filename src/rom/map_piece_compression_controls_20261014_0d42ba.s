.setcpu "65816"
.segment "CODE"
.org $42BA
map_control_0d42ba:
    .byte $E2 ; previous-row copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
