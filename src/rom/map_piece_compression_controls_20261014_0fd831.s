.setcpu "65816"
.segment "CODE"
.org $D831
map_control_0fd831:
    .byte $E0 ; previous-row copy escape
    .byte $30 ; row-distance/count
