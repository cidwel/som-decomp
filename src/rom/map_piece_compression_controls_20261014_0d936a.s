.setcpu "65816"
.segment "CODE"
.org $936A
map_control_0d936a:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
