.setcpu "65816"
.segment "CODE"
.org $BC60
map_control_0ebc60:
    .byte $E0 ; previous-row copy escape
    .byte $DF ; row-distance/count
