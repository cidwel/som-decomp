.setcpu "65816"
.segment "CODE"
.org $321C
map_control_0d321c:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
