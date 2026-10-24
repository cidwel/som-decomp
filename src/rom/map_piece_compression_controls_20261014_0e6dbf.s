.setcpu "65816"
.segment "CODE"
.org $6DBF
map_control_0e6dbf:
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
