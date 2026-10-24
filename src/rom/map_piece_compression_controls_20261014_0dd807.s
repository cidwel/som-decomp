.setcpu "65816"
.segment "CODE"
.org $D807
map_control_0dd807:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
