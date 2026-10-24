.setcpu "65816"
.segment "CODE"
.org $64B8
map_control_0c64b8:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
