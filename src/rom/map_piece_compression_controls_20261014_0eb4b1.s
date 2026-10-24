.setcpu "65816"
.segment "CODE"
.org $B4B1
map_control_0eb4b1:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
