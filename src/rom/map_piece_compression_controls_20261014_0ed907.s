.setcpu "65816"
.segment "CODE"
.org $D907
map_control_0ed907:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
