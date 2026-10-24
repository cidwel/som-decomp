.setcpu "65816"
.segment "CODE"
.org $695F
map_control_0d695f:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
