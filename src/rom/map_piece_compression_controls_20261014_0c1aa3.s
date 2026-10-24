.setcpu "65816"
.segment "CODE"
.org $1AA3
map_control_0c1aa3:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
