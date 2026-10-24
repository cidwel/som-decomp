.setcpu "65816"
.segment "CODE"
.org $78B7
map_control_0c78b7:
    .byte $E0 ; previous-row copy escape
    .byte $14 ; row-distance/count
