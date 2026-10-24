.setcpu "65816"
.segment "CODE"
.org $3DC0
map_control_0f3dc0:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
