.setcpu "65816"
.segment "CODE"
.org $FB6D
map_control_0cfb6d:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
