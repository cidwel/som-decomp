.setcpu "65816"
.segment "CODE"
.org $EB86
map_control_0eeb86:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
