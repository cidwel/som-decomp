.setcpu "65816"
.segment "CODE"
.org $C0A4
map_control_0dc0a4:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
