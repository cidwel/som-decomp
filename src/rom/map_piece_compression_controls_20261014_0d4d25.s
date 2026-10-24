.setcpu "65816"
.segment "CODE"
.org $4D25
map_control_0d4d25:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
