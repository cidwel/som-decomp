.setcpu "65816"
.segment "CODE"
.org $7B93
map_control_0e7b93:
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
