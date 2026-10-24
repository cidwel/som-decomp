.setcpu "65816"
.segment "CODE"
.org $EF19
map_control_0eef19:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
