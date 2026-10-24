.setcpu "65816"
.segment "CODE"
.org $BCF7
map_control_0dbcf7:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
