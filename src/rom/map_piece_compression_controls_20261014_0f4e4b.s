.setcpu "65816"
.segment "CODE"
.org $4E4B
map_control_0f4e4b:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
