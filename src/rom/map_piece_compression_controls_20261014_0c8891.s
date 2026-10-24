.setcpu "65816"
.segment "CODE"
.org $8891
map_control_0c8891:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
