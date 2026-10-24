.setcpu "65816"
.segment "CODE"
.org $37F8
map_control_0c37f8:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
