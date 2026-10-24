.setcpu "65816"
.segment "CODE"
.org $0C6A
map_control_0d0c6a:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
