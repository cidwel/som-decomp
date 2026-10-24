.setcpu "65816"
.segment "CODE"
.org $4973
map_control_0d4973:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
