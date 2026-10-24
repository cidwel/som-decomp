.setcpu "65816"
.segment "CODE"
.org $B6B1
map_control_0db6b1:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
