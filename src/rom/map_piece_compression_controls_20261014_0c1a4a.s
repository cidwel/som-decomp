.setcpu "65816"
.segment "CODE"
.org $1A4A
map_control_0c1a4a:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
