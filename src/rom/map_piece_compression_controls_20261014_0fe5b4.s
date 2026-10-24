.setcpu "65816"
.segment "CODE"
.org $E5B4
map_control_0fe5b4:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
