.setcpu "65816"
.segment "CODE"
.org $F945
map_control_0ef945:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
