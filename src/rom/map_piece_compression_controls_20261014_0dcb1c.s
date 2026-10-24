.setcpu "65816"
.segment "CODE"
.org $CB1C
map_control_0dcb1c:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
