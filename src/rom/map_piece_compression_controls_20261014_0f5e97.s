.setcpu "65816"
.segment "CODE"
.org $5E97
map_control_0f5e97:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
