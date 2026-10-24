.setcpu "65816"
.segment "CODE"
.org $BF28
map_control_0fbf28:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
