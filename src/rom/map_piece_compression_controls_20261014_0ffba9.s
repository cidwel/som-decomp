.setcpu "65816"
.segment "CODE"
.org $FBA9
map_control_0ffba9:
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
