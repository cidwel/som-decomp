.setcpu "65816"
.segment "CODE"
.org $7369
map_control_0d7369:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
