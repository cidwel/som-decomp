.setcpu "65816"
.segment "CODE"
.org $2949
map_control_0c2949:
    .byte $E0 ; previous-row copy escape
    .byte $22 ; row-distance/count
