.setcpu "65816"
.segment "CODE"
.org $4096
map_control_0c4096:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
