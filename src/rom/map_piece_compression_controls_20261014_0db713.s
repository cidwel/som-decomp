.setcpu "65816"
.segment "CODE"
.org $B713
map_control_0db713:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
