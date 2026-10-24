.setcpu "65816"
.segment "CODE"
.org $4BBD
map_control_0e4bbd:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
