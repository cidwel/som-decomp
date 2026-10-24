.setcpu "65816"
.segment "CODE"
.org $FB5D
map_control_0cfb5d:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
