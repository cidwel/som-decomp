.setcpu "65816"
.segment "CODE"
.org $BF8A
map_control_0fbf8a:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
