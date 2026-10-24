.setcpu "65816"
.segment "CODE"
.org $B8CF
map_control_0fb8cf:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
