.setcpu "65816"
.segment "CODE"
.org $CC02
map_control_0ecc02:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
