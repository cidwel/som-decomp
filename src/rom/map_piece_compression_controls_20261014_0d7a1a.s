.setcpu "65816"
.segment "CODE"
.org $7A1A
map_control_0d7a1a:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
