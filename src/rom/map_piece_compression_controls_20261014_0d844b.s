.setcpu "65816"
.segment "CODE"
.org $844B
map_control_0d844b:
    .byte $E0 ; previous-row copy escape
    .byte $2F ; row-distance/count
