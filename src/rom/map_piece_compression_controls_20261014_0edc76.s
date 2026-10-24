.setcpu "65816"
.segment "CODE"
.org $DC76
map_control_0edc76:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
