.setcpu "65816"
.segment "CODE"
.org $4595
map_control_0e4595:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
