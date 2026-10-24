.setcpu "65816"
.segment "CODE"
.org $655B
map_control_0d655b:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
