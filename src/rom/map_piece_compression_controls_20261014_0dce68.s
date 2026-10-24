.setcpu "65816"
.segment "CODE"
.org $CE68
map_control_0dce68:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
