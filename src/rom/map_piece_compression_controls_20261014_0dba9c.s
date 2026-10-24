.setcpu "65816"
.segment "CODE"
.org $BA9C
map_control_0dba9c:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
