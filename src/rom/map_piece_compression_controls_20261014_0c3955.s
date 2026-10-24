.setcpu "65816"
.segment "CODE"
.org $3955
map_control_0c3955:
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
