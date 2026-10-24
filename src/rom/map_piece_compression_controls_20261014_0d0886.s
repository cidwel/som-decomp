.setcpu "65816"
.segment "CODE"
.org $0886
map_control_0d0886:
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
