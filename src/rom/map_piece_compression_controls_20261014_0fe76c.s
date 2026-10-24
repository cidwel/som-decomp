.setcpu "65816"
.segment "CODE"
.org $E76C
map_control_0fe76c:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
