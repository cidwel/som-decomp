.setcpu "65816"
.segment "CODE"
.org $B43B
map_control_0db43b:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
