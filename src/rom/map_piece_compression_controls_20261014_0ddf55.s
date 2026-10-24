.setcpu "65816"
.segment "CODE"
.org $DF55
map_control_0ddf55:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
