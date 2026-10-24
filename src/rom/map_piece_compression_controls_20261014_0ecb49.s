.setcpu "65816"
.segment "CODE"
.org $CB49
map_control_0ecb49:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
