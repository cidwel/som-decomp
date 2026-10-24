.setcpu "65816"
.segment "CODE"
.org $5C1C
map_control_0c5c1c:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
