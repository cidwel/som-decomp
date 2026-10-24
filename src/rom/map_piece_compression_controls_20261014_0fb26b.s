.setcpu "65816"
.segment "CODE"
.org $B26B
map_control_0fb26b:
    .byte $E0 ; previous-row copy escape
    .byte $21 ; row-distance/count
