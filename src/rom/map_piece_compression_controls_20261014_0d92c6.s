.setcpu "65816"
.segment "CODE"
.org $92C6
map_control_0d92c6:
    .byte $E0 ; previous-row copy escape
    .byte $3D ; row-distance/count
