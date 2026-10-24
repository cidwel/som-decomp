.setcpu "65816"
.segment "CODE"
.org $6CE4
map_control_0c6ce4:
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
