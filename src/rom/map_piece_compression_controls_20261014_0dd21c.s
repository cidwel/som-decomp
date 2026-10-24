.setcpu "65816"
.segment "CODE"
.org $D21C
map_control_0dd21c:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
