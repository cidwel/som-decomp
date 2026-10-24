.setcpu "65816"
.segment "CODE"
.org $B321
map_control_0db321:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
