.setcpu "65816"
.segment "CODE"
.org $CC82
map_control_0ecc82:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
