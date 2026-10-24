.setcpu "65816"
.segment "CODE"
.org $EB90
map_control_0deb90:
    .byte $E0 ; previous-row copy escape
    .byte $56 ; row-distance/count
