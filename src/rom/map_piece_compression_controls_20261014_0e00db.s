.setcpu "65816"
.segment "CODE"
.org $00DB
map_control_0e00db:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
