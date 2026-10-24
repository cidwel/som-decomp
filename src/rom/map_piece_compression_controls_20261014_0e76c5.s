.setcpu "65816"
.segment "CODE"
.org $76C5
map_control_0e76c5:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $8A ; row-distance/count
