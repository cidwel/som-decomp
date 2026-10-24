.setcpu "65816"
.segment "CODE"
.org $210A
map_control_0c210a:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
