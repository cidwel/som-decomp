.setcpu "65816"
.segment "CODE"
.org $B785
map_control_0db785:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
