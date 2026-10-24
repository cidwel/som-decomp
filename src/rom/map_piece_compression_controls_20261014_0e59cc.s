.setcpu "65816"
.segment "CODE"
.org $59CC
map_control_0e59cc:
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
