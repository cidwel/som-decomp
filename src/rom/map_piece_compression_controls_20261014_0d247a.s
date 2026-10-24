.setcpu "65816"
.segment "CODE"
.org $247A
map_control_0d247a:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
