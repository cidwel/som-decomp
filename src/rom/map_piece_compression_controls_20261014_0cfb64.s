.setcpu "65816"
.segment "CODE"
.org $FB64
map_control_0cfb64:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
