.setcpu "65816"
.segment "CODE"
.org $28A4
map_control_0e28a4:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
