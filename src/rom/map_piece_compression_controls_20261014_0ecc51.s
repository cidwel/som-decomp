.setcpu "65816"
.segment "CODE"
.org $CC51
map_control_0ecc51:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
