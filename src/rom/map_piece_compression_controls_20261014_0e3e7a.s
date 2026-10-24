.setcpu "65816"
.segment "CODE"
.org $3E7A
map_control_0e3e7a:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
