.setcpu "65816"
.segment "CODE"
.org $72D1
map_control_0c72d1:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
