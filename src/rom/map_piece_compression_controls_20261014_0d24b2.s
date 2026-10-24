.setcpu "65816"
.segment "CODE"
.org $24B2
map_control_0d24b2:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
