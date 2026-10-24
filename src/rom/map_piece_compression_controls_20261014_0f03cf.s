.setcpu "65816"
.segment "CODE"
.org $03CF
map_control_0f03cf:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
