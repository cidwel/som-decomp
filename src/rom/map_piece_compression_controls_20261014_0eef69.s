.setcpu "65816"
.segment "CODE"
.org $EF69
map_control_0eef69:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
