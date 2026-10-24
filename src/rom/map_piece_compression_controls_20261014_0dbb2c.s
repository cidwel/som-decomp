.setcpu "65816"
.segment "CODE"
.org $BB2C
map_control_0dbb2c:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
