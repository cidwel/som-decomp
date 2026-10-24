.setcpu "65816"
.segment "CODE"
.org $FB2C
map_control_0cfb2c:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
