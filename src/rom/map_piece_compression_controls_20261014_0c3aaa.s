.setcpu "65816"
.segment "CODE"
.org $3AAA
map_control_0c3aaa:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
