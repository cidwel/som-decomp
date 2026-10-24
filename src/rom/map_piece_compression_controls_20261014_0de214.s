.setcpu "65816"
.segment "CODE"
.org $E214
map_control_0de214:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
