.setcpu "65816"
.segment "CODE"
.org $FDD0
map_control_0efdd0:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
