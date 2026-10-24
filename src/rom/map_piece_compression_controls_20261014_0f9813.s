.setcpu "65816"
.segment "CODE"
.org $9813
map_control_0f9813:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
