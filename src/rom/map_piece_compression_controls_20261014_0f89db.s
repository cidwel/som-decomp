.setcpu "65816"
.segment "CODE"
.org $89DB
map_control_0f89db:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
