.setcpu "65816"
.segment "CODE"
.org $945E
map_control_0f945e:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
