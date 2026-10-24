.setcpu "65816"
.segment "CODE"
.org $0D4A
map_control_0e0d4a:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
