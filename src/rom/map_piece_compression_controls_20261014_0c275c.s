.setcpu "65816"
.segment "CODE"
.org $275C
map_control_0c275c:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
