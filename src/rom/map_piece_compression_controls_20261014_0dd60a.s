.setcpu "65816"
.segment "CODE"
.org $D60A
map_control_0dd60a:
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
