.setcpu "65816"
.segment "CODE"
.org $5A2A
map_control_0e5a2a:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
