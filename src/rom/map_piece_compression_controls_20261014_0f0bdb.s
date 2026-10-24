.setcpu "65816"
.segment "CODE"
.org $0BDB
map_control_0f0bdb:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
