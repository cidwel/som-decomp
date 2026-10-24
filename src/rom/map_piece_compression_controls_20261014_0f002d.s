.setcpu "65816"
.segment "CODE"
.org $002D
map_control_0f002d:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
