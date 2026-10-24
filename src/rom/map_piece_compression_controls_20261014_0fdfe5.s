.setcpu "65816"
.segment "CODE"
.org $DFE5
map_control_0fdfe5:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
