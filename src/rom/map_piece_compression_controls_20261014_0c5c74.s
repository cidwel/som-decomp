.setcpu "65816"
.segment "CODE"
.org $5C74
map_control_0c5c74:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
