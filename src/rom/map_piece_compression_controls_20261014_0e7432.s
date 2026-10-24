.setcpu "65816"
.segment "CODE"
.org $7432
map_control_0e7432:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $9E ; row-distance/count
