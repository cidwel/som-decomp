.setcpu "65816"
.segment "CODE"
.org $44BF
map_control_0d44bf:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
