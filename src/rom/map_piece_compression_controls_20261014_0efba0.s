.setcpu "65816"
.segment "CODE"
.org $FBA0
map_control_0efba0:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
