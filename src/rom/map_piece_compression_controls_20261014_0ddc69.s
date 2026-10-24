.setcpu "65816"
.segment "CODE"
.org $DC69
map_control_0ddc69:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
