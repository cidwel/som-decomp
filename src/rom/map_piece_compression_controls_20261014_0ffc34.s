.setcpu "65816"
.segment "CODE"
.org $FC34
map_control_0ffc34:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
