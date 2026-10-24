.setcpu "65816"
.segment "CODE"
.org $FB1D
map_control_0cfb1d:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
