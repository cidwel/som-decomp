.setcpu "65816"
.segment "CODE"
.org $FBA0
map_control_0cfba0:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
