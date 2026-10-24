.setcpu "65816"
.segment "CODE"
.org $D080
map_control_0dd080:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
