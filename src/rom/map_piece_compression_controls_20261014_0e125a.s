.setcpu "65816"
.segment "CODE"
.org $125A
map_control_0e125a:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
