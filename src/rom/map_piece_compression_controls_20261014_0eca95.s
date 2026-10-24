.setcpu "65816"
.segment "CODE"
.org $CA95
map_control_0eca95:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
