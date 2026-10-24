.setcpu "65816"
.segment "CODE"
.org $0D9A
map_control_0d0d9a:
    .byte $E0 ; previous-row copy escape
    .byte $1D ; row-distance/count
