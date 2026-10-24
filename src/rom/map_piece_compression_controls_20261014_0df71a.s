.setcpu "65816"
.segment "CODE"
.org $F71A
map_control_0df71a:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
