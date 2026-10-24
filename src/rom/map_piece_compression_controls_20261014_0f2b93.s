.setcpu "65816"
.segment "CODE"
.org $2B93
map_control_0f2b93:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
