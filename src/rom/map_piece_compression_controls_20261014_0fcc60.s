.setcpu "65816"
.segment "CODE"
.org $CC60
map_control_0fcc60:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
