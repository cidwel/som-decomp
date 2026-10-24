.setcpu "65816"
.segment "CODE"
.org $664C
map_control_0c664c:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
