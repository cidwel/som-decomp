.setcpu "65816"
.segment "CODE"
.org $52D2
map_control_0e52d2:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
