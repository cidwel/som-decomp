.setcpu "65816"
.segment "CODE"
.org $DFF6
map_control_0edff6:
    .byte $E0 ; previous-row copy escape
    .byte $28 ; row-distance/count
