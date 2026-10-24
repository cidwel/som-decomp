.setcpu "65816"
.segment "CODE"
.org $2B34
map_control_0c2b34:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
