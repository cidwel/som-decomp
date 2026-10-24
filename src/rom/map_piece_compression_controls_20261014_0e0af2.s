.setcpu "65816"
.segment "CODE"
.org $0AF2
map_control_0e0af2:
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
