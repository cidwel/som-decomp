.setcpu "65816"
.segment "CODE"
.org $6AFC
map_control_0d6afc:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
