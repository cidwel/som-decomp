.setcpu "65816"
.segment "CODE"
.org $BE20
map_control_0fbe20:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
