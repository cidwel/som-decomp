.setcpu "65816"
.segment "CODE"
.org $005C
map_control_0e005c:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
