.setcpu "65816"
.segment "CODE"
.org $CC6B
map_control_0ecc6b:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
