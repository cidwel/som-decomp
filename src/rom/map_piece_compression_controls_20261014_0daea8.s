.setcpu "65816"
.segment "CODE"
.org $AEA8
map_control_0daea8:
    .byte $E0 ; previous-row copy escape
    .byte $31 ; row-distance/count
