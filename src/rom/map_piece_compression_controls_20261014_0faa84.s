.setcpu "65816"
.segment "CODE"
.org $AA84
map_control_0faa84:
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
