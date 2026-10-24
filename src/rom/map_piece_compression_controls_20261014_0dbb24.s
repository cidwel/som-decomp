.setcpu "65816"
.segment "CODE"
.org $BB24
map_control_0dbb24:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
