.setcpu "65816"
.segment "CODE"
.org $1FCA
map_control_0c1fca:
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
