.setcpu "65816"
.segment "CODE"
.org $F5A4
map_control_0ef5a4:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
