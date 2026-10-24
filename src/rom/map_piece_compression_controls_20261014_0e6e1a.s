.setcpu "65816"
.segment "CODE"
.org $6E1A
map_control_0e6e1a:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
