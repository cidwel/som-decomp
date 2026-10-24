.setcpu "65816"
.segment "CODE"
.org $F0DF
map_control_0ef0df:
    .byte $E0 ; previous-row copy escape
    .byte $2B ; row-distance/count
