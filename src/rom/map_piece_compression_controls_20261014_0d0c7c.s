.setcpu "65816"
.segment "CODE"
.org $0C7C
map_control_0d0c7c:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
