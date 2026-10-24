.setcpu "65816"
.segment "CODE"
.org $C0F5
map_control_0dc0f5:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
