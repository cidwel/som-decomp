.setcpu "65816"
.segment "CODE"
.org $F965
map_control_0ef965:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
