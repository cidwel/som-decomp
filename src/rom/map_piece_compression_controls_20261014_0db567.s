.setcpu "65816"
.segment "CODE"
.org $B567
map_control_0db567:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
