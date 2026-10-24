.setcpu "65816"
.segment "CODE"
.org $FB3A
map_control_0cfb3a:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
