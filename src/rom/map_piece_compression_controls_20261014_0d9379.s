.setcpu "65816"
.segment "CODE"
.org $9379
map_control_0d9379:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
