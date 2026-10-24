.setcpu "65816"
.segment "CODE"
.org $114C
map_control_0e114c:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
