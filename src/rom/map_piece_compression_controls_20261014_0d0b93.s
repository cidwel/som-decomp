.setcpu "65816"
.segment "CODE"
.org $0B93
map_control_0d0b93:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $E2 ; previous-row copy count
