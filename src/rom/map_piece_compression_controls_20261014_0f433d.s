.setcpu "65816"
.segment "CODE"
.org $433D
map_control_0f433d:
    .byte $E0 ; previous-row copy escape
    .byte $18 ; row-distance/count
