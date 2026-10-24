.setcpu "65816"
.segment "CODE"
.org $B75B
map_control_0db75b:
    .byte $E0 ; previous-row copy escape
    .byte $8D ; row-distance/count
