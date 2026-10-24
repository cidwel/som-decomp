.setcpu "65816"
.segment "CODE"
.org $902A
map_control_0e902a:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
