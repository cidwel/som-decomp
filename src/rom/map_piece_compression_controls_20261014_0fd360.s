.setcpu "65816"
.segment "CODE"
.org $D360
map_control_0fd360:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
