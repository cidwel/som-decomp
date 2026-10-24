.setcpu "65816"
.segment "CODE"
.org $DF6C
map_control_0ddf6c:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
