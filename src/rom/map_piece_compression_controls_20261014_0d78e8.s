.setcpu "65816"
.segment "CODE"
.org $78E8
map_control_0d78e8:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
