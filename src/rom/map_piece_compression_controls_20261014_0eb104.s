.setcpu "65816"
.segment "CODE"
.org $B104
map_control_0eb104:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
