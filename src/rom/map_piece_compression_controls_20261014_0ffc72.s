.setcpu "65816"
.segment "CODE"
.org $FC72
map_control_0ffc72:
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
