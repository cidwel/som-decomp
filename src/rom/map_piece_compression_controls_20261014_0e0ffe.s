.setcpu "65816"
.segment "CODE"
.org $0FFE
map_control_0e0ffe:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
