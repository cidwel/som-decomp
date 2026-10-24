.setcpu "65816"
.segment "CODE"
.org $34E4
map_control_0c34e4:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
