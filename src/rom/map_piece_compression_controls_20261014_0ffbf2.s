.setcpu "65816"
.segment "CODE"
.org $FBF2
map_control_0ffbf2:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
