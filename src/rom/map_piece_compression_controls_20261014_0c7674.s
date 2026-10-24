.setcpu "65816"
.segment "CODE"
.org $7674
map_control_0c7674:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
