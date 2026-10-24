.setcpu "65816"
.segment "CODE"
.org $C926
map_control_0dc926:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
