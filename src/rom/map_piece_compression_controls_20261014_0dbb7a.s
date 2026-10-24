.setcpu "65816"
.segment "CODE"
.org $BB7A
map_control_0dbb7a:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
