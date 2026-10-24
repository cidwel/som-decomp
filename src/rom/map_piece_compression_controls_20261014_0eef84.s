.setcpu "65816"
.segment "CODE"
.org $EF84
map_control_0eef84:
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
