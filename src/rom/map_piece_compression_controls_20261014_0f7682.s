.setcpu "65816"
.segment "CODE"
.org $7682
map_control_0f7682:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
