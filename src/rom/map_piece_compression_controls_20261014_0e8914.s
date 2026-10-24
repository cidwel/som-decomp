.setcpu "65816"
.segment "CODE"
.org $8914
map_control_0e8914:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
