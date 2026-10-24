.setcpu "65816"
.segment "CODE"
.org $FBE5
map_control_0efbe5:
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
