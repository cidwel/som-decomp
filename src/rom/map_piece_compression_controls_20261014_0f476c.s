.setcpu "65816"
.segment "CODE"
.org $476C
map_control_0f476c:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
