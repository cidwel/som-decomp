.setcpu "65816"
.segment "CODE"
.org $F8AF
map_control_0ef8af:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
