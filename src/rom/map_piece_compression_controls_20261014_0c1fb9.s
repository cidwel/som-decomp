.setcpu "65816"
.segment "CODE"
.org $1FB9
map_control_0c1fb9:
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
