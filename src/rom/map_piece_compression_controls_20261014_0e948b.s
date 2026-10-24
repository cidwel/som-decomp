.setcpu "65816"
.segment "CODE"
.org $948B
map_control_0e948b:
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
