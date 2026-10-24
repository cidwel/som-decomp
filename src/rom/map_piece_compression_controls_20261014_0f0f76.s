.setcpu "65816"
.segment "CODE"
.org $0F76
map_control_0f0f76:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
