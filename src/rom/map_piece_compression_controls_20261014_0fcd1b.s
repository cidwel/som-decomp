.setcpu "65816"
.segment "CODE"
.org $CD1B
map_control_0fcd1b:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
