.setcpu "65816"
.segment "CODE"
.org $F0D4
map_control_0df0d4:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
