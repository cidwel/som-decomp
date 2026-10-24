.setcpu "65816"
.segment "CODE"
.org $F36C
map_control_0ff36c:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
