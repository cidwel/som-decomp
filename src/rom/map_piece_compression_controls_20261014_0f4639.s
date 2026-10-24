.setcpu "65816"
.segment "CODE"
.org $4639
map_control_0f4639:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
