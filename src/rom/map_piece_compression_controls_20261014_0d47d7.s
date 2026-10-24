.setcpu "65816"
.segment "CODE"
.org $47D7
map_control_0d47d7:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
