.setcpu "65816"
.segment "CODE"
.org $8777
map_control_0d8777:
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
