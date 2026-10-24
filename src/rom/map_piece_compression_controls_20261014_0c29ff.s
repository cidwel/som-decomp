.setcpu "65816"
.segment "CODE"
.org $29FF
map_control_0c29ff:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
