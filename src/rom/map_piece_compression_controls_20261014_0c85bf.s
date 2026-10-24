.setcpu "65816"
.segment "CODE"
.org $85BF
map_control_0c85bf:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $42 ; row-distance/count
