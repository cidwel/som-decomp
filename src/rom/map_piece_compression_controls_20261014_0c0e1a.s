.setcpu "65816"
.segment "CODE"
.org $0E1A
map_control_0c0e1a:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $83 ; row-distance/count
