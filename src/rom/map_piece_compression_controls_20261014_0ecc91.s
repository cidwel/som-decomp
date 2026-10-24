.setcpu "65816"
.segment "CODE"
.org $CC91
map_control_0ecc91:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
