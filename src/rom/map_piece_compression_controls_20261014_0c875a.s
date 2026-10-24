.setcpu "65816"
.segment "CODE"
.org $875A
map_control_0c875a:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
