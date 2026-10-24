.setcpu "65816"
.segment "CODE"
.org $EB6A
map_control_0eeb6a:
    .byte $E0 ; previous-row copy escape
    .byte $1B ; row-distance/count
