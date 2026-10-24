.setcpu "65816"
.segment "CODE"
.org $8A3C
map_control_0c8a3c:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
